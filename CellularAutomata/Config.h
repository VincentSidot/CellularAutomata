#include "SFML\Graphics.hpp"
typedef struct
{
	size_t x;
	size_t y;
}vector;



#pragma once
class Config
{
public:
	Config(
		vector grid,
		vector cell,
		sf::Color alive,
		sf::Color dead
	)
	: _grid{ grid.x - (grid.x % cell.x),grid.y - (grid.y % cell.y) }, _cell{ cell.x,cell.y }, _alive{ _alive }, _dead{ _dead }
	{

	}
	~Config() {}

#define ret(type,name,varname) inline type name() const { return varname ; }
//--------------------------------------------------------------------------

	ret(vector,grid,_grid)
	ret(vector,cell,_cell)
	ret(sf::Color,dead,_dead)
	ret(sf::Color,alive,_alive)

//--------------------------------------------------------------------------

public:
	vector _grid;
	vector _cell;
	sf::Color _alive;
	sf::Color _dead;

};

