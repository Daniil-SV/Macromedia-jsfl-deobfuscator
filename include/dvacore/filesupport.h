#pragma once

#include "dvacore.h"

namespace dvacore
{
	namespace filesupport
	{
		class ByteStream_base {
			virtual int iword(int);
			virtual int pword(int);
			virtual void* xalloc();
		};

		// INPUT

		class IByteStream : public ByteStream_base {
			virtual bool AtTheEnd();
			virtual void ReadBlock(uchar*, uint32_t);
		};

		class IBufferByteStream : public IByteStream {
			virtual void CurPos(uint64_t);
			virtual void* Get();
		};

		// class size: 128
		IBufferByteStream* CreateIBufferByteStream(const uint8_t* data, uint64_t length)
		{
			char* ptr = new char[128]();

			FARPROC function = GetProcAddress(dvacore::lib, "??0IBufferByteStream@filesupport@dvacore@@QEAA@PEBE_K@Z");
			((void(*)(IBufferByteStream*, const uint8_t*, uint64_t))function)((IBufferByteStream*)ptr, data, length);

			return (IBufferByteStream*)ptr;
		}

		class IStdByteStream : public IByteStream {
			virtual void CurPos();
			virtual uint64_t Length();
		};

		// OUTPUT
		class OByteStream : public ByteStream_base {
			virtual void WriteBlock(const uint8_t, int);
		};

		//this is probably an ida error or something else, but this class is inherited from bytestream base class, which is a little illogical, I will correct this moment a bit
		class OBufferByteStream : public OByteStream {
			virtual uint64_t CurPos();
			virtual void CurPos(int64_t);
			virtual void Put(uchar);
			virtual void Truncate(uint64_t, bool);
		};

		// Class size: 120
		OBufferByteStream* CreateOBufferByteStream(const uint8_t* data, uint64_t length)
		{
			char* ptr = new char[120]();

			FARPROC function = GetProcAddress(dvacore::lib, "??0OBufferByteStream@filesupport@dvacore@@QEAA@PEAE_K@Z");
			((void(*)(OBufferByteStream*, const uint8_t*, uint64_t))function)((OBufferByteStream*)ptr, data, length);

			return (OBufferByteStream*)ptr;
		}
	}
}