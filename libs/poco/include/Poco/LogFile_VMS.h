//
// LogFile_VMS.h
//
// $Id: //poco/1.3/Foundation/include/Poco/LogFile_VMS.h#1 $
//
// Library: Foundation
// Package: Logging
// Module:  LogFile
//
// Definition of the LogFileImpl class using C I/O with OpenVMS extensions.
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


#ifndef Foundation_LogFile_VMS_INCLUDED
#define Foundation_LogFile_VMS_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Timestamp.h"
#include <stdio.h>


namespace Poco {


class Foundation_API LogFileImpl
	/// The implementation of LogFile for OpenVMS.
	/// The C Standard Library functions for file I/O
	/// are used with OpenVMS-specific extensions to
	/// control sharing and locking behavior.
{
public:
	LogFileImpl(const std::string& path);
	~LogFileImpl();
	void writeImpl(const std::string& text);
	UInt64 sizeImpl() const;
	Timestamp creationDateImpl() const;
	const std::string& pathImpl() const;

private:
	std::string   _path;
	mutable FILE* _file;
	Timestamp     _creationDate;
};


} // namespace Poco


#endif // Foundation_LogFile_VMS_INCLUDED
