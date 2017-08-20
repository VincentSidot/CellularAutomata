#include "Application.h"





Application::Application(Config config) : rRand{ config.probability() }, cConfig{ config }, bRunning{ false }
{}

Application::~Application()
{
	if (hThread != INVALID_HANDLE_VALUE)
	{
		TerminateThread(hThread, EXIT_FAILURE);
		CloseHandle(hThread);
	}
}

void Application::run()
{
	Grid current(cConfig);
	rwWindow.create(sf::VideoMode(cConfig.screen().x, cConfig.screen().y), "Cellular automata");
	//Creating thread
	bRunning = true;
	hThread = CreateThread(NULL, 0, ((LPTHREAD_START_ROUTINE)&Thread), this, 0, &dwThreadID);
	if (hThread == INVALID_HANDLE_VALUE)
	{
		MessageBox(
			NULL,
			(LPCWSTR)L"Error can't start thread",
			(LPCWSTR)L"Error can't start thread",
			MB_OK | MB_ICONERROR
		);
		exit(EXIT_FAILURE);
	}
	//Main program loop
	while (rwWindow.isOpen())
	{
		sf::Event eEvent;
		while (rwWindow.pollEvent(eEvent))
		{
			if (eEvent.type == sf::Event::Closed)
			{
				bRunning = false;
				WaitForSingleObject(hThread, INFINITE);
				CloseHandle(hThread);
				rwWindow.close();
				break;
			}
			//delete grid if more than one
			if (qGrid.size() > 1) qGrid.pop();

			//set background to dead color
			rwWindow.clear(cConfig.dead());

			//display grid if one is avaible
			if (qGrid.size() > 0) rwWindow.draw(qGrid.front());

			rwWindow.display();
		}
	}

}

Grid Application::CreateGrid(void)
{
	Grid firstGrid = Grid(cConfig);
	for (size_t i = 0; i < firstGrid.row(); i++)
	{
		for (size_t j = 0; j < firstGrid.col(); j++)
		{
			firstGrid(i, j).setAlive(rRand());
		}
	}
	return firstGrid;
}


Grid Application::nextGrid(Grid &patern)
{
	Grid old = patern;
	for (size_t i = 0; i < patern.row(); i++)
	{
		for (size_t j = 0; j < patern.col(); j++)
		{
			DWORD alive = countCell(old, i, j);
			if (alive == 3)
			{
				patern(i, j).setAlive(true);
			}
			else if (alive < 2 || alive > 3)
			{
				patern(i, j).setAlive(false);
			}
		}
	}
	return patern;
}
