#include "Cell.h"

#define _color (_alive)?_config.alive():_config.dead()

#define vx(i) _vertex[i].position.x
#define vy(i) _vertex[i].position.y
#define vc(i) _vertex[i].color
#define _x _config.cell().x
#define _y _config.cell().y

Cell& Cell::operator=(const Cell & g)
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

void Cell::set(const Cell & c)
{
	this->_alive = c.isAlive();
	this->_config = c.config();
	this->_vertex = c.vertex();
	this->_i = c.pos().x;
	this->_j = c.pos().y;
}

void Cell::set(const Config & config, const vector & pos, const bool alive)
{
	this->_i = pos.x;
	this->_j = pos.y;
	this->_config.operator=(config);
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

#undef vx
#undef vy
#undef vc
#undef _x
#undef _y
#undef _color

