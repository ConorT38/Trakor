//============================================================================
// Name        : Connection.h
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <iostream>
#include "Configuration.h"
#include "mysql_connection.h"

#ifndef DATABASE_CONNECTION_H_
#define DATABASE_CONNECTION_H_

class Connection
{
public:
    Connection(Configuration *databaseConfig);
    std::unique_ptr<sql::Connection> CreateConnection();
};

#endif /* DATABASE_CONNECTION_H_ */