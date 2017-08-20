#pragma once
#include "FastMatrix.h"
#include "Cell.h"
#include "Config.h"

class Grid : public FastMatrix<Cell>, public sf::Drawable
{
public:
	Grid(Config config);
	Grid(Grid const &g);
	Grid& operator=(Grid const &g);
	Config config() const;
	bool isAlive(size_t i, size_t j) const;
	~Grid();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (size_t i = 0; i < this->size(); i++)
		{
			target.draw(this->_data[i]);
		}
	}
protected:
	Config _config;
};

