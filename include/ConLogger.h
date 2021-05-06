/*
 * ConLogger.h
 *
 *  Created on: 28 Apr 2021
 *      Author: conor
 */

#ifndef INCLUDE_LOGGER_CONLOGGER_H_
#define INCLUDE_LOGGER_CONLOGGER_H_

#include "Logger.h"

class ConLogger : public Logger
{
	public:
	void log(LogLevel level, std::string message);
};

#endif /* INCLUDE_LOGGER_CONLOGGER_H_ */
