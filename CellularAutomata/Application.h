#pragma once
#include <queue>
#include <Windows.h>
#include "SFML\Main.hpp"
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Random.h"
#include "Grid.h"


class Application
{
public:
	Application(Config config);
	~Application();
	
	void run();

protected:
	friend DWORD WINAPI Thread(LPCVOID arg)
	{
		Application* aThis = (Application*)arg;
		Grid patern = aThis->CreateGrid();
		aThis->qGrid.push(patern);
		do
		{
			aThis->qGrid.push(aThis->nextGrid(patern));
		} while (aThis->bRunning);
		return 0;
	}
	Grid CreateGrid(void);
	Grid nextGrid(Grid &patern);
	inline DWORD countCell(const Grid &grid,size_t i,size_t j)
	{
		DWORD count = 0;
		for (int ip = -1; ip <= 1; ip++)
		{
			for (int jp = -1; jp <= 1; jp++)
			{
				if ((ip != 0 || jp != 0) && i+ip < grid.row() && i+ip > 0 && j+jp > 0 && j+jp < grid.col())
				{
					if (grid.isAlive(i + ip, j + ip)) count++;
				}
			}
		}
		return count;
	}

	bool bRunning; //init
	HANDLE hThread;
	DWORD dwThreadID;
	std::queue<Grid> qGrid;
	sf::RenderWindow rwWindow;
	Random rRand; //init
	Config cConfig; //init
};

