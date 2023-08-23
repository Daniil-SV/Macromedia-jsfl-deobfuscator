#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>

namespace dvacore
{
	typedef unsigned char uchar;
	HINSTANCE lib = LoadLibrary(L"dvacore");
}