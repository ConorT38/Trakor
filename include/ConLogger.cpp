/*
 * Logger.cpp
 *
 *  Created on: 26 Apr 2021
 *      Author: conor
 */

#include "Logger.h"
#include "ConLogger.h"


void ConLogger::log(LogLevel level, std::string message)
{
	switch(level){
	case LogLevel::INFO:
		std::cout << "[INFO] " << message << std::endl;
		break;
	default:
		std::cout << "oi";
		break;
	}
}

