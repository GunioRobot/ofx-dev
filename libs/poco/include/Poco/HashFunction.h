//
// HashFunction.h
//
// $Id: //poco/1.3/Foundation/include/Poco/HashFunction.h#2 $
//
// Library: Foundation
// Package: Hashing
// Module:  HashFunction
//
// Definition of the HashFunction class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_HashFunction_INCLUDED
#define Foundation_HashFunction_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Hash.h"


namespace Poco {


//@ deprecated
template <class T>
struct HashFunction
	/// A generic hash function.
{
	UInt32 operator () (T key, UInt32 maxValue) const
		/// Returns the hash value for the given key.
	{
		return ((UInt32) hash(key)) % maxValue;
	}
};


//@ deprecated
template <>
struct HashFunction<std::string>
	/// A generic hash function.
{
	UInt32 operator () (const std::string& key, UInt32 maxValue) const
		/// Returns the hash value for the given key.
	{
		return ((UInt32) hash(key)) % maxValue;
	}
};


} // namespace Poco


#endif // Foundation_HashFunctions_INCLUDED
