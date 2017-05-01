//============================================================================
// Name        : NullStream.h
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 avr. 2017
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef NULLSTREAM_H_
#define NULLSTREAM_H_

#include <iostream>

class NullBuf : public std::streambuf
{
public:
	virtual std::streamsize xsputn (const char * s, std::streamsize n);
	virtual int overflow (int c);
};

class NullStream : public std::ostream
{
public:
	NullStream();
private:
	NullBuf buf;
};

extern NullStream cnull;

#endif // NULLSTREAM_H_
