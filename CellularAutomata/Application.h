#include "Config.h"

#pragma once
class Application
{
public:
	Application(Config config);
	~Application();

	void run();

private: 



	Config _config;
};

