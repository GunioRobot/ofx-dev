//
// SHA1Engine.h
//
// $Id: //poco/1.3/Foundation/include/Poco/SHA1Engine.h#2 $
//
// Library: Foundation
// Package: Crypt
// Module:  SHA1Engine
//
// Definition of class SHA1Engine.
//
// Secure Hash Standard SHA-1 algorithm
// (FIPS 180-1, see http://www.itl.nist.gov/fipspubs/fip180-1.htm)
//
// Based on the public domain implementation by Peter C. Gutmann
// on 2 Sep 1992, modified by Carl Ellison to be SHA-1.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_SHA1Engine_INCLUDED
#define Foundation_SHA1Engine_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/DigestEngine.h"


namespace Poco {


class Foundation_API SHA1Engine: public DigestEngine
	/// This class implementes the SHA-1 message digest algorithm.
	/// (FIPS 180-1, see http://www.itl.nist.gov/fipspubs/fip180-1.htm)
{
public:
	enum
	{
		BLOCK_SIZE  = 64,
		DIGEST_SIZE = 20
	};

	SHA1Engine();
	~SHA1Engine();

	unsigned digestLength() const;
	void reset();
	const DigestEngine::Digest& digest();

protected:
	void updateImpl(const void* data, unsigned length);

private:
	void transform();
	static void byteReverse(UInt32* buffer, int byteCount);

	typedef UInt8 BYTE;

	struct Context
	{
		UInt32 digest[5]; // Message digest
		UInt32 countLo;   // 64-bit bit count
		UInt32 countHi;
		UInt32 data[16];  // SHA data buffer
		UInt32 slop;      // # of bytes saved in data[]
	};

	Context _context;
	DigestEngine::Digest _digest;

	SHA1Engine(const SHA1Engine&);
	SHA1Engine& operator = (const SHA1Engine&);
};


} // namespace Poco


#endif // Foundation_SHA1Engine_INCLUDED
