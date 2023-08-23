#pragma once

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)

#define JSStr(string) (unsigned short*)(WIDEN(string))

typedef struct JSContext JSContext;

typedef struct JSObject JSObject;

typedef long long JSValue;

typedef long long JSBool;

typedef bool(*JSNative)(JSContext* cx, JSObject* obj, unsigned int argc, JSValue argv[], JSValue* rval);

extern "C"
{
	/****************************************************************************** Private data types, macros, and globals  ****************************************************************************/

	typedef struct {
		JSObject* libObj;
		JSBool(*defineFunction)(JSObject* libObj, unsigned short* name, JSNative call, unsigned int nargs);
		unsigned short* (*valueToString)(JSContext* cx, JSValue v, unsigned int* pLength);
		unsigned char* (*valueToBytes)(JSContext* cx, JSValue v, unsigned int* pLength);
		JSBool(*valueToInteger)(JSContext* cx, JSValue v, long* lp);
		JSBool(*valueToDouble)(JSContext* cx, JSValue v, double* dp);
		JSBool(*valueToBoolean)(JSContext* cx, JSValue v, JSBool* bp);
		JSBool(*valueToObject)(JSContext* cx, JSValue v, JSObject** op);
		JSBool(*stringToValue)(JSContext* cx, unsigned short* b, unsigned int sz, JSValue* vp);
		JSBool(*bytesToValue)(JSContext* cx, unsigned char* b, unsigned int sz, JSValue* vp);
		JSBool(*doubleToValue)(JSContext* cx, double dv, JSValue* vp);
		unsigned short* (*objectName)(JSObject* obj);
		JSObject* (*newArrayObject)(JSContext* cx, unsigned int length, JSValue* vp);
		long (*getArrayLength)(JSContext* cx, JSObject* obj);
		JSBool(*getElement)(JSContext* cx, JSObject* obj, unsigned int idx, JSValue* vp);
		JSBool(*setElement)(JSContext* cx, JSObject* obj, unsigned int idx, JSValue* vp);
		JSBool(*executeScript)(JSContext* cx, JSObject* obj, unsigned short* script, unsigned int sz, unsigned short* file, unsigned int lineNum, JSValue* rval);
		JSBool(*reportError)(JSContext* cx, unsigned short* error, unsigned int sz);

		JSBool(*UserMathErrorFunction)(JSContext* cx);  // just returns 0

		void* unk2; // __int64 __fastcall sub_1416AE170(__int64 a1, __int64 a2, _DWORD *a3)

		void* unk3; //__int64 __fastcall sub_1416AE310(wchar_t *a1, void *a2, int a3, __int64 *a4)

		JSBool(*UserMathErrorFunction_2)(JSContext* cx); // has the same adress as UserMathErrorFunction

		void* unk5; // __int64 __fastcall sub_1416AE760(const unsigned __int16 *a1)	// Run file ?

		void* unk6; // __int64 __fastcall charNode::raw_length(charNode *this) // just returns 1 // the next 3 functions have the same address
		void* unk7;
		void* unk8;
		void* unk9;
		void* unk11; // _BOOL8 __fastcall sub_1416AE900(const unsigned __int16 *a1) // very similar to sub_1416AE760

		void* unk12; // _BOOL8 __fastcall sub_1416AEA30(const unsigned __int16 *a1) // probably something like open a file

		void* unk13; // __int64 __fastcall sub_1416AF460(__int64 a1, const unsigned __int16 *a2, const unsigned __int16 *a3) // something scary

		void* unk14; // _BOOL8 __fastcall sub_1416AFBA0(const unsigned __int16 *a1) // very similar to sub_1416AE900

		JSBool(*UserMathErrorFunction_3)(JSContext* cx); // has the same adress as UserMathErrorFunction

		void* unk16; // __int64 __fastcall sub_1416AFCF0(const unsigned __int16 *a1, unsigned int *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5) // something to do with paths and time

		void* unk17; // __int64 __fastcall sub_1416B00D0(const unsigned __int16 *a1, char a2) // Set file data and time?

		JSBool(*createDir)(unsigned short* path);
		JSBool(*removeDir)(unsigned short* path);
		JSBool(*removeFileOrDir)(unsigned short* path);

		void* unk21; // __int64 __fastcall sub_1416B0A60(__int64 context,__int64 a2,__int64 script,int a4,__int64 filepath,int file_line,__int64 result)

		void* unk22; // __int64 __fastcall sub_1416B0AF0(wchar_t *a1, const unsigned __int16 *a2, __int64 a3, __int64 *a4) // read file

		void* unk23; //__int64 __fastcall sub_1416B0F00(const unsigned __int16* a1,__int16* a2,const unsigned __int16* a3,__int64 a4,__int64* a5) // write file

		void* unk24; // has the same adress as charNode::raw_length

		void* unk25; // __int64 __fastcall sub_1416B1260(const unsigned __int16 *a1, const unsigned __int16 *a2, __int64 *a3)

		void* unk26; // __int64 __fastcall sub_1416AEB70(__int64 a1, dvacore::string *a2, int a3) // smth like report error

		void* unk27; // unsigned __int64 __fastcall sub_1416AEBF0(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)

		void* unk28;
		void* unk29;

		JSBool(*UserMathErrorFunction_4)(JSContext* cx); // has the same adress as UserMathErrorFunction

													   //				unused		unused
		void* unk31; // __int64 __fastcall sub_1416AE350(wchar_t *a1, __int64 a2, __int64 a3, __int64 *a4) // something strange

		void* unk32; // char __fastcall sub_140F5AB00(CString *a1, __int64 a2)

		void* unk33; // void *__fastcall sub_1416AEF90(__int64 a1, const unsigned __int16 *a2)

		void* unk34; // void *__fastcall sub_1416AF1C0(__int64 a1, const unsigned __int16 *a2) // smth like sub_1416AEF90

		void* unk35; // unsigned __int16 *sub_1416AF3B0()

		void* unk36; // __int64 __fastcall sub_1416B16E0(__int64 a1, __int64 a2, __int64 a3)

		void* unk37;

		void* unk38; // __int64 __fastcall sub_1416B18C0(__int64 context,const unsigned __int16* a2,dvacore::string* script,unsigned int a4,__int64 filepath,int fileline,__int64 result)

		void* unk39;
	} MM_Environment;

	MM_Environment mmEnv;

#ifdef _WIN32
#ifndef _MAC
	__declspec (dllexport) void MM_InitWrapper(MM_Environment* env, unsigned int envSize);

#ifdef MM_Terminator
	__declspec (dllexport) void MM_Terminate();
#endif

#endif
#else
	extern void MM_InitWrapper(MM_Environment* env, unsigned int envSize);

#ifdef MM_Terminator
	__declspec (dllexport) void MM_Terminate();
#endif

#endif
}

void MM_InitWrapper(MM_Environment* env, unsigned int envSize)
{
	char** envPtr = (char**)env;
	char** mmPtr = (char**)(&mmEnv);
	char** envEnd = (char**)((char*)envPtr + envSize);
	char** mmEnd = (char**)((char*)mmPtr + sizeof(MM_Environment));

	/* Copy fields from env to mmEnv, one pointer at a time */
	while (mmPtr < mmEnd && envPtr < envEnd)
		*mmPtr++ = *envPtr++;

	/* If env doesn't define all of mmEnv's fields, set extras to NULL */
	while (mmPtr < mmEnd)
		*mmPtr++ = (char*)0;

#ifdef MM_Initializer
	extern void MM_Init();
	MM_Init();
#endif
}

// JS ENV Functions

bool JS_DefineFunction(unsigned short* name, JSNative call, unsigned int nargs)
{
	if (mmEnv.defineFunction)
	{
		return (*mmEnv.defineFunction)(mmEnv.libObj, name, call, nargs);
	}

	return false;
}

bool JS_ValueToString(JSContext* ctx, JSValue& value, unsigned short** string, unsigned int* length)
{
	if (mmEnv.valueToString && string && length)
	{
		*string = (*(mmEnv.valueToString))(ctx, value, length);

		if (*string) return true;
	}

	return false;
}

bool JS_ValueToBytes(JSContext* ctx, JSValue& value, unsigned char** bytes, unsigned int* length)
{
	if (mmEnv.valueToBytes && bytes)
	{
		*bytes = (*(mmEnv.valueToBytes))(ctx, value, length);

		if (*bytes) return true;
	}

	return false;
}

bool JS_ValueToInteger(JSContext* ctx, JSValue& value, long* integer)
{
	if (mmEnv.valueToInteger && integer)
	{
		return (*mmEnv.valueToInteger)(ctx, value, integer);
	}

	return false;
}

bool JS_ValueToDouble(JSContext* ctx, JSValue& value, double* number)
{
	if (mmEnv.valueToDouble && number)
	{
		return (*mmEnv.valueToDouble)(ctx, value, number);
	}

	return false;
}

bool JS_ValueToBoolean(JSContext* ctx, JSValue& value, bool* boolean)
{
	if (mmEnv.valueToBoolean && boolean)
	{
		return (*mmEnv.valueToBoolean)(ctx, value, (JSBool*)boolean);
	}

	return false;
}

bool JS_ValueToObject(JSContext* ctx, JSValue& value, JSObject** object)
{
	if (mmEnv.valueToObject && object)
	{
		return (*mmEnv.valueToObject)(ctx, value, object);
	}

	return false;
}

bool JS_StringToValue(JSContext* ctx, unsigned short* string, unsigned int length, JSValue& rval)
{
	if (mmEnv.stringToValue && string && rval)
	{
		return (*mmEnv.stringToValue)(ctx, string, length, &rval);
	}
	return false;
}

bool JS_BytesToValue(JSContext* ctx, unsigned char* bytes, unsigned int length, JSValue& rval)
{
	if (mmEnv.bytesToValue && bytes && rval)
	{
		return (*mmEnv.bytesToValue)(ctx, bytes, length, &rval);
	}
	return false;
}

bool JS_DoubleToValue(JSContext* ctx, double number, JSValue& rval)
{
	if (mmEnv.doubleToValue && number && rval)
	{
		return (*mmEnv.doubleToValue)(ctx, number, &rval);
	}
	return false;
}

bool JS_IntegerToValue(long integer, JSValue& rval)
{
	rval = ((JSValue)(integer) << 1) | 0x1;
	return true;
}

bool JS_BooleanToValue(bool boolean, JSValue& rval)
{
	rval = ((JSValue)(boolean) << 3) | 0x6;
	return true;
}

bool JS_ObjectToValue(JSObject* object, JSValue& rval)
{
	rval = (JSValue)object;
	return true;
}

bool JS_ObjectName(JSObject* object, unsigned short** name)
{
	if (mmEnv.objectName && object && name)
	{
		*name = (*mmEnv.objectName)(object);
		if (*name) return true;
	}

	return false;
}

bool JS_NewArrayObject(JSContext* ctx, unsigned int length, JSObject** rval, JSValue* values = nullptr)
{
	if (mmEnv.newArrayObject && rval)
	{
		*rval = (*mmEnv.newArrayObject)(ctx, length, values);
		if (*rval) return true;
	}

	return false;
}

bool JS_GetArrayLength(JSContext* ctx, JSObject* object, long* length)
{
	if (mmEnv.getArrayLength && object)
	{
		*length = (*mmEnv.getArrayLength)(ctx, object);
		return true;
	}

	*length = -1;
	return false;
}

bool JS_GetElement(JSContext* ctx, JSObject* object, unsigned int index, JSValue* rval)
{
	if (mmEnv.getElement && object && rval)
	{
		return (*mmEnv.getElement)(ctx, object, index, rval);
	}

	return false;
}

bool JS_SetElement(JSContext* ctx, JSObject* object, unsigned int index, JSValue* value)
{
	if (mmEnv.setElement && object && value)
	{
		return (*mmEnv.setElement)(ctx, object, index, value);
	}

	return false;
}

bool JS_ExecuteScript(JSContext* ctx, JSObject* object, unsigned short* script, unsigned int length, JSValue* rval)
{
	if (mmEnv.executeScript && script && rval)
	{
		return mmEnv.executeScript(ctx, object, script, length, JSStr(__FILE__), __LINE__, rval);
	}

	return false;
}

bool JS_ExecuteScript(JSContext* ctx, unsigned short* message, unsigned int length = 0)
{
	if (mmEnv.reportError && message)
	{
		mmEnv.reportError(ctx, message, length);
	}

	return false;
}
