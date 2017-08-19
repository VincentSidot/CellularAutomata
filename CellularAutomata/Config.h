#include "SFML\Graphics.hpp"
typedef struct _v
{
	size_t x;
	size_t y;
	inline struct _v& operator=(const struct _v &v)
	{
		x = v.x;
		y = v.y;
	}
}vector;



#pragma once
class Config
{
public:
	Config() {}
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

	ret(vector, grid, _grid)
		ret(vector, cell, _cell)
		ret(sf::Color, dead, _dead)
		ret(sf::Color, alive, _alive)

		//--------------------------------------------------------------------------
#undef ret
		inline Config& operator=(const Config &c);
public:
	vector _grid;
	vector _cell;
	sf::Color _alive;
	sf::Color _dead;
};

