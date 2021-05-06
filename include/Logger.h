/*
 * Logger.h
 *
 *  Created on: 26 Apr 2021
 *      Author: conor
 */

#ifndef LOGGER_LOGGER_H_
#define LOGGER_LOGGER_H_

#include "LogLevel.h"
#include <iostream>

class Logger
{
public:
	virtual ~Logger(){};
    virtual void log(LogLevel level, std::string message) = 0;
};

#endif /* LOGGER_LOGGER_H_ */
