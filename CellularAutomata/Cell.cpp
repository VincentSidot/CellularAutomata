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
