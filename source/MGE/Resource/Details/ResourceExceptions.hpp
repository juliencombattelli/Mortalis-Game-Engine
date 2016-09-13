//============================================================================
// Name        : ResourceExceptions.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 9, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCEEXCEPTIONS_HPP_
#define RESOURCEEXCEPTIONS_HPP_

#include <stdexcept>

namespace mge
{

class ResourceException : public std::exception
{
public:
	explicit ResourceException(const char* message) :
		m_msg(message) {}
   	explicit ResourceException(const std::string& message) :
   		m_msg(message) {}
    virtual ~ResourceException() noexcept {}
    virtual const char* what() const noexcept override {return m_msg.c_str();}

protected:
    std::string m_msg;
};

class LoadResourceException : public ResourceException
{
public:
   	explicit LoadResourceException(const std::string& filename) :
		ResourceException("Unable to load resource : \"" + filename + "\".") {}
    virtual ~LoadResourceException() noexcept {}
    virtual const char* what() const noexcept override {return m_msg.c_str();}
};


} // namespace mge

#endif // RESOURCEEXCEPTIONS_HPP_
