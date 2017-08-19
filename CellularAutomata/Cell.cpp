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

inline void Cell::set(const Config & config, const vector & pos, const bool alive)
{
	this->_i = pos.x;
	this->_j = pos.y;
	this->_config = config;
	this->_alive = alive;
#pragma warning( push )
#pragma warning( disable : 4244)
	vx(0) = _i * _x;
	vy(0) = (_j + 1) * _y;
	vc(0) = _color;

	vx(1) = _i * _x;
	vy(1) = _j * _y;
	vc(1) = _color;

	vx(2) = (_i + 1) * _x;
	vy(2) = _j * _y;
	vc(2) = _color;

	vx(3) = (_i + 1) * _x;
	vy(3) = (_j + 1) * _y;
	vc(3) = _color;
#pragma warning( pop ) 
}