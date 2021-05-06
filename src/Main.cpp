//============================================================================
// Name        : Main.cpp
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <pistache/endpoint.h>

#include "Controller/SearchController.h"
#include "ConLogger.h"
#include "LogLevel.h"

using namespace Pistache;

int main()
{
	Port port(9080);
	Address address(Ipv4::any(), port);

	SearchController searchController(address);
	int threads = 2;

	ConLogger *logger = new ConLogger;

	logger->log(LogLevel::INFO, "Listening on port: 9080");

	searchController.init(threads);
	searchController.start();
}
