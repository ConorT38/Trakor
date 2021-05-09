//============================================================================
// Name        : Connection.cpp
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "Connection.h"
#include "Configuration.h"

static std::string url;
static std::string user;
static std::string pass;
static std::string database;

Connection::Connection(Configuration *databaseConfiguration)
{
    url = databaseConfiguration->GetConfig("trakor.database.host");
    user = databaseConfiguration->GetConfig("trakor.database.user");
    pass = databaseConfiguration->GetConfig("trakor.database.password");
    database = databaseConfiguration->GetConfig("trakor.database.schema");

    sql::Driver *driver = get_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
}

std::unique_ptr<sql::Connection> Connection::CreateConnection()
{
    sql::Driver *driver = get_driver_instance();
    std::unique_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
    return con;
}