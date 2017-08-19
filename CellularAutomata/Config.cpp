#include "Config.h"

inline Config& Config::operator=(const Config &c)
{
	this->_alive = c.alive();
	this->_cell = c.cell();
	this->_grid = c.grid();
	this->_dead = c.dead();
}
