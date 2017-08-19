#include "SFML\Graphics.hpp"
#include "Config.h"

#define _color (_alive)?_config.alive():_config.dead()

#define vx(i) _vertex[i].position.x
#define vy(i) _vertex[i].position.y
#define vc(i) _vertex[i].color
#define _x _config.cell().x
#define _y _config.cell().y

#pragma once
class Cell :
	public sf::Drawable
{
public:
	Cell(){}
	Cell(size_t i, size_t j,Config config,bool alive = false) : _i{ i }, _j{ j }, _config{ config },_vertex{sf::PrimitiveType::Quads,4},_alive{alive}
	{
//disabling warning because converting size_t to float
#pragma warning( push )
#pragma warning( disable : 4244)
		vx(0) = i * _x;
		vy(0) = (j + 1) * _y;
		vc(0) = _color;

		vx(1) = i * _x;
		vy(1) = j * _y;
		vc(1) = _color;

		vx(2) = (i + 1) * _x;
		vy(2) = j * _y;
		vc(2) = _color;

		vx(3) = (i + 1) * _x;
		vy(3) = (j + 1) * _y;
		vc(3) = _color;
#pragma warning( pop ) 
	}
	~Cell();
	inline Cell& operator=(const Cell &g);
	inline bool isAlive() const { return _alive; }
	inline void setAlive(bool alive) 
	{
		if (alive != _alive)
		{
			_alive = alive;
			vc(0) = _color;
			vc(1) = _color;
			vc(2) = _color;
			vc(3) = _color;
		}
	}
	inline vector pos() const {
		return{ _i,_j };
	}
	inline Config config() const { return _config; }
	inline sf::VertexArray vertex() const { return _vertex; }
	inline void set(const Cell &c);
	inline void set(const Config &config, const vector &pos, const bool alive = false);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(_vertex, states);
	}
private:
	sf::VertexArray _vertex;
	Config _config;
	bool _alive;
	size_t _i, _j;
};
