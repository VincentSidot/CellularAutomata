#include "Config.h"

Config& Config::operator=(const Config& c)
{
	this->_alive = c.alive();
	this->_cell = c.cell();
	this->_screen = c.screen();
	this->_dead = c.dead();
	this->_probability = c.probability();
	return *this;
}
