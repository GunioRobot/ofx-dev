//
// WindowsConsoleChannel.h
//
// $Id: //poco/1.3/Foundation/include/Poco/WindowsConsoleChannel.h#2 $
//
// Library: Foundation
// Package: Logging
// Module:  WindowsConsoleChannel
//
// Definition of the WindowsConsoleChannel class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_WindowsConsoleChannel_INCLUDED
#define Foundation_WindowsConsoleChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"
#include "Poco/Mutex.h"
#include "Poco/UnWindows.h"


namespace Poco {


class Foundation_API WindowsConsoleChannel: public Channel
	/// A channel that writes to the Windows console.
	///
	/// Only the message's text is written, followed
	/// by a newline.
	///
	/// If POCO has been compiled with POCO_WIN32_UTF8,
	/// log messages are assumed to be UTF-8 encoded, and
	/// are converted to UTF-16 prior to writing them to the
	/// console. This is the main difference to the ConsoleChannel
	/// class, which cannot handle UTF-8 encoded messages on Windows.
	///
	/// Chain this channel to a FormattingChannel with an
	/// appropriate Formatter to control what is contained
	/// in the text.
	///
	/// Only available on Windows platforms.
{
public:
	WindowsConsoleChannel();
		/// Creates the WindowsConsoleChannel.

	void log(const Message& msg);
		/// Logs the given message to the channel's stream.

protected:
	~WindowsConsoleChannel();

private:
	HANDLE _hConsole;
	bool   _isFile;
};


} // namespace Poco


#endif // Foundation_WindowsConsoleChannel_INCLUDED
