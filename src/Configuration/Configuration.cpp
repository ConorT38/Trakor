//============================================================================
// Name        : Configuration.cpp
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : -----
//============================================================================

#include <stddef.h>
#include <fstream>
#include <sstream>
#include "Configuration.h"

Configuration *Configuration::instance = nullptr;
Configuration::ConfigMap Configuration::configMap = {};

Configuration *Configuration::GetInstance()
{
    if (!instance)
    {
        try
        {
            /*
             try load configuration file properties into map
            and create new instance of Configuration.
            */
            Configuration::LoadConfigurationFile();
            instance = new Configuration();
        }
        catch (std::exception &ex)
        {
            /* Handle exception here.*/
            std::cout << &ex << std::endl;
        }
    }
    return instance;
}

std::string Configuration::GetConfig(std::string configName)
{
    if (configName.empty())
    {
        throw new std::invalid_argument("configName cannot be null/empty.");
    }

    try
    {
        const std::string &value = configMap.at(configName);
        return value.c_str();
    }
    catch (const std::out_of_range &)
    {
        std::cout << "Key '" << configName.c_str() << "' not found" << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << &ex << std::endl;
    }
    return "";
}

void Configuration::LoadConfigurationFile()
{
    std::ifstream inConfigFile("../trakor.cfg");
    std::string configLine;

    while (std::getline(inConfigFile, configLine))
    {
        std::istringstream isLine(configLine);
        std::string key;

        if (std::getline(isLine, key, '='))
        {
            std::string value;
            if (std::getline(isLine, value))
            {
                configMap.insert(std::pair<std::string, std::string>(key.c_str(), value.c_str()));
            }
        }
    }
}