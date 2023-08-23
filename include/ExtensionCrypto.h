#pragma once

#include "dvacore/filesupport.h"
using namespace dvacore::filesupport;

// Adobe Animate 22.0.3

namespace ExtensionsCrypto
{
	auto IsExtensionEncrypted = *((bool(*)(IBufferByteStream*))0x00000001416DBCD0);
	auto DecryptExtension = *((void(*)(IBufferByteStream*, OBufferByteStream*, bool))0x00000001416DBB90);
}