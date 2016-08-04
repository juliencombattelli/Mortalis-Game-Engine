//============================================================================
// Name        : Status.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef STATUS_HPP_
#define STATUS_HPP_

#include <cstdint>

namespace mge
{

class Status
{
public:
	enum Value : std::int8_t
	{
		StatusOpenGLInitFailed = -5,  ///< OpenGL initialization failed
		StatusAppMissingAsset  = -4,  ///< Application failed due to missing asset file
		StatusAppStackEmpty    = -3,  ///< Application States stack is empty
		StatusAppInitFailed    = -2,  ///< Application initialization failed
		StatusError            = -1,  ///< General error status response
		StatusNoError          =  0,  ///< General no error status response
		StatusAppOK            =  0,  ///< Application quit without error
		StatusOK               =  1   ///< OK status response
	};

	Status();
	Status(Value);

	Status(const Status&);
	Status& operator=(const Status&);
	Status& operator=(Value);
	operator Value() const;

	~Status() = default;

	bool isError() const;
	bool isOk() const;

private:

	Value m_value;
};

bool operator==(const Status& lhs, Status::Value rhs);
bool operator!=(const Status& lhs, Status::Value rhs);
bool operator> (const Status& lhs, Status::Value rhs);
bool operator< (const Status& lhs, Status::Value rhs);
bool operator>=(const Status& lhs, Status::Value rhs);
bool operator<=(const Status& lhs, Status::Value rhs);

} // namespace mge



#endif // STATUS_HPP_
