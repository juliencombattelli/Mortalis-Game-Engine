//============================================================================
// Name        : InputFileWrapper.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef INPUTFILEWRAPPER_HPP_
#define INPUTFILEWRAPPER_HPP_

#include <fstream>

namespace mge
{

class InputFileWrapper
{
public:
	bool loadFromFile(const std::string& filename)
	{
		m_file.open(filename);
		return m_file.is_open();
	}

	std::ifstream& getStream()
	{
		return m_file;
	}

private:
	std::ifstream m_file;
};

} // namespace mge

#endif // INPUTFILEWRAPPER_HPP_
