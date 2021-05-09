//============================================================================
// Name        : Main.cpp
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Controller/SearchController.h"
#include "ConLogger.h"
#include "LogLevel.h"
#include "Configuration/Configuration.h"
#include "Http/Routes.h"
#include "Database/Connection.h"

using namespace Pistache;

int main()
{
	ConLogger *logger = new ConLogger;
	Configuration *configuration = Configuration::GetInstance();

	Connection *databaseConnection = new Connection(configuration);

	const int port = std::stoi(configuration->GetConfig("trakor.port"));

	// sql::Statement *stmt;
	// sql::ResultSet *res;
	// stmt = con->createStatement();
	// res = stmt->executeQuery("SELECT * from torrents");
	// while (res->next())
	// {
	// 	std::cout << "\t... MySQL replies: ";
	// 	/* Access column data by alias or column name */
	// 	std::cout << res->getString("title") << std::endl;
	// 	std::cout << "\t... MySQL says it again: ";
	// 	/* Access column data by numeric offset, 1 is the first column */
	// 	std::cout << res->getString(1) << std::endl;
	// }
	Routes::InitRoutes(Ipv4::any(), port);
}
