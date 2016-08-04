#ifndef TYPE_HPP_INCLUDED
#define TYPE_HPP_INCLUDED

#include <Engine/Log/LogMacro.hpp>

#include <string>
#include <iostream>
#include <fstream>

#define INFO_LEVEL   0  ///< Defines the value for rpg::SeverityInfo
#define WARN_LEVEL   1  ///< Defines the value for rpg::SeverityWarning
#define ERROR_LEVEL  2  ///< Defines the value for rpg::SeverityError
#define FATAL_LEVEL  3  ///< Defines the value for rpg::Severity
#define NO_LOG_LEVEL 4  ///< Defines the value for no logging

namespace rpg
{

enum class Action : int8_t
{
	pause,
	accept,
	refuse,
	moveUp,
	moveDown,
	moveLeft,
	moveRight,

	count,
	invalid
};

enum StateID
{
    MENU = 0,
    EXPLORATION = 10,
    COMBAT = 25
};

enum StatusType
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

enum SeverityType
{
    // Logger severity types range from 0 to 5
    SeverityInfo          = INFO_LEVEL,   ///< Informational severity type
    SeverityWarning       = WARN_LEVEL,   ///< Warning severity type
    SeverityError         = ERROR_LEVEL,  ///< Error severity type
    SeverityFatal         = FATAL_LEVEL   ///< Fatal severity type
};

//typedef boost::signals2::signal< void (int, std::string) > signal_t;
//typedef boost::signals2::connection                        connection_t;


}

#endif // TYPE_HPP_INCLUDED
