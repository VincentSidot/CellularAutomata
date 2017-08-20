#pragma once
#include "SFML\Graphics.hpp"
typedef struct _v
{
	size_t x;
	size_t y;
	inline struct _v& operator=(const struct _v &v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
}vector;



class Config
{
public:
	Config() {}
	Config(
		vector screen,
		vector cell,
		sf::Color alive,
		sf::Color dead,
		double probability
	)
	: _screen{ screen.x - (screen.x % cell.x),screen.y - (screen.y % cell.y) },
		_cell{ cell.x,cell.y },
		_alive{ _alive },
		_dead{ _dead },
		_probability{probability}
	{}
	~Config() {}

#define ret(type,name,varname) inline type name() const { return varname ; }
//--------------------------------------------------------------------------

	ret(vector, screen, _screen)
	ret(vector, cell, _cell)
	ret(sf::Color, dead, _dead)
	ret(sf::Color, alive, _alive)
	ret(double,probability, _probability)

//--------------------------------------------------------------------------
#undef ret
		Config& operator=(const Config& c);
public:
	double _probability;
	vector _screen;
	vector _cell;
	sf::Color _alive;
	sf::Color _dead;
};

