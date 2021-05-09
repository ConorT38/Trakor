//============================================================================
// Name        : Configuration.h
// Author      : Conor Thompson
// Version     :
// Copyright   : Your copyright notice
// Description : Singleton Configuration class.
//============================================================================

#ifndef CONFIGURATION_CONFIGURATION_H_
#define CONFIGURATION_CONFIGURATION_H_

#include <iostream>
#include <map>

class Configuration
{

public:
    static Configuration *GetInstance();
    std::string GetConfig(std::string configName);

private:
    typedef std::map<std::string, std::string> ConfigMap;
    static ConfigMap configMap;
    static Configuration *instance;
    Configuration(){};
    static void LoadConfigurationFile();
};

#endif /* CONFIGURATION_CONFIGURATION_H_ */