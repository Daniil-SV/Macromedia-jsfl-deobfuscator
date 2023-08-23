#define MM_Initializer
#include "jsapi.h"

#include <filesystem>
namespace fs = std::filesystem;

#include <iostream>
#include <fstream>

#include "dvacore/filesupport.h"
#include "ExtensionCrypto.h"

// Helper functions
fs::path GetPath(JSContext* context, JSValue value)
{
	uint32_t pathSize = 0;
	unsigned short* pathPtr = nullptr;
	std::u16string path;

	if (JS_ValueToString(context, value, &pathPtr, &pathSize)) {
		path = std::u16string(pathPtr, pathPtr + (pathSize * sizeof(char16_t)));
	}

	return fs::path(path);
}

// Main functions

bool DecodeJSFL(JSContext* ctx, JSObject* obj, unsigned int argc, JSValue argv[], JSValue* rval) noexcept
{
	using namespace dvacore::filesupport;

	if (argc != 2) return false;

	bool succes = false;
	std::u16string message = u"OK";

	fs::path inputPath = GetPath(ctx, argv[0]);
	fs::path outputPath = GetPath(ctx, argv[1]);

	if (!fs::exists(inputPath)) {
		message = u"Input File is not exist";
		goto RETURN_RES;
	}

	{
		std::ifstream file(inputPath, std::ios::binary | std::ios::ate);
		uint64_t filesize = file.tellg();
		file.seekg(0, std::ios::beg);

		std::vector<char> filebuffer(filesize);
		file.read(filebuffer.data(), filesize);

		std::vector<char> outputBuffer(filesize + 3);

		IBufferByteStream* input = CreateIBufferByteStream((uint8_t*)filebuffer.data(), filebuffer.size());
		OBufferByteStream* output = CreateOBufferByteStream((uint8_t*)outputBuffer.data(), filebuffer.size());

		if (ExtensionsCrypto::IsExtensionEncrypted(input))
		{
			ExtensionsCrypto::DecryptExtension(input, output, true);
			std::ofstream outputFile(outputPath, std::ios::binary);
			outputFile.write(outputBuffer.data(), strlen(outputBuffer.data()));
		}
		else
		{
			message = u"File is not obfuscated";
		}
	}

	succes = true;
	// Result processing
RETURN_RES:
	JSObject* result = nullptr;
	if (!JS_NewArrayObject(ctx, 2, &result)) return false;

	JSValue succesValue;
	JS_BooleanToValue(succes, succesValue);
	JSValue messageValue;
	JS_StringToValue(ctx, (unsigned short*)message.data(), message.length(), messageValue);

	JS_SetElement(ctx, result, 0, &succesValue);
	JS_SetElement(ctx, result, 1, &messageValue);

	JS_ObjectToValue(result, *rval);
	return true;
}

void MM_Init()
{
	JS_DefineFunction(JSStr("decode"), &DecodeJSFL, 2);
}