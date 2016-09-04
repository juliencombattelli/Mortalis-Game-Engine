//============================================================================
// Name        : Status.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MGE/Core/Status/Status.hpp>

namespace mge
{

Status::Status() : m_value(Status::StatusOK)
{

}

Status::Status(Status::Value value) : m_value(value)
{

}

Status::Status(const Status& status) : m_value(status.m_value)
{

}

Status& Status::operator=(const Status& status)
{
	m_value = status.m_value;
	return *this;
}

Status& Status::operator=(Status::Value value)
{
	m_value = value;
	return *this;
}

Status::operator Status::Value() const
{
	return m_value;
}

bool Status::isError() const
{
	return m_value < 0;
}

bool Status::isOk() const
{
	return m_value >= 0;
}

bool operator==(const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) == rhs;
}

bool operator!=(const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) != rhs;
}

bool operator> (const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) > rhs;
}

bool operator< (const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) < rhs;
}

bool operator>=(const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) >= rhs;
}

bool operator<=(const Status& lhs, Status::Value rhs)
{
	return Status::Value(lhs) <= rhs;
}

} // namespace mge
