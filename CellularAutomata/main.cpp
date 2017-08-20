#include <iostream>
#include <Windows.h>
#include "Application.h"
#include "Config.h"


int main(int argc, char** argv)
{
	vector screen{ 800,600 };
	vector cell{ 8,6 };
	Config config{ screen,cell,sf::Color::White,sf::Color::Black,1.0 / 6.0 };
	Application app{ config };
	app.run();
	return 0;
}