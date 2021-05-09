//============================================================================
// Name        : Routes.cpp
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <pistache/endpoint.h>
#include "Routes.h"
#include "SearchController.h"
#include "ConLogger.h"

// Set the number of threads to use to be the number of logical processors on the machine
// and if it can't find this for some reason then just set the amount to '2' threads.
const auto threads = std::thread::hardware_concurrency() == 0 ? 2 : std::thread::hardware_concurrency();

ConLogger *logger = new ConLogger;

void Routes::InitRoutes(Pistache::IP ip, Pistache::Port port)
{
    Address address(ip, port);

    SearchController searchController(address);

    logger->log(LogLevel::INFO, "Listening on port: 9080");

    searchController.init(threads);
    searchController.start();
};
