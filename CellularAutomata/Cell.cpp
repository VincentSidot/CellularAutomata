#include "Cell.h"


inline Cell& Cell::operator=(const Cell & g)
{
	this->_alive = g.isAlive();
	this->_config = g.config();
	this->_vertex = g.vertex();
	this->_i = g.pos().x;
	this->_j = g.pos().y;
	return *this;
}

Cell::~Cell()
{
}

inline void Cell::set(const Cell & c)
{
	this->_alive = c.isAlive();
	this->_config = c.config();
	this->_vertex = c.vertex();
	this->_i = c.pos().x;
	this->_j = c.pos().y;
}
