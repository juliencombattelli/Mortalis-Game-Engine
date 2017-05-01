//============================================================================
// Name        : NullStream.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 avr. 2017
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#include "NullStream.h"

std::streamsize NullBuf::xsputn (const char * s, std::streamsize n)
{
	return n;
}

int NullBuf::overflow (int c)
{
	return 1;
}

NullStream::NullStream() :
	std::ostream (&buf)
{

}

NullStream cnull;


