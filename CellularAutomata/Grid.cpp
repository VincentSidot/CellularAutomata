#include "Grid.h"


Grid::Grid(Config config) : FastMatrix<Cell>{config.screen().x/config.cell().x,config.screen().y/config.cell().y} , _config{ config }
{
	for (size_t i = 0; i < this->row(); i++)
	{
		for (size_t j = 0; j < this->col(); j++)
		{
			_data[i + _row * j] = Cell(i, j, _config, false);
		}
	}
	
}

Grid::Grid(Grid const & g) : FastMatrix<Cell>(g)
{
	_config = g.config();
}

Grid & Grid::operator=(Grid const & g)
{
	this->realoc(g.row(), g.col());
	this->Fill(g);
	this->_config = g.config();
	return *this;
	// TODO: insert return statement here
}

Config Grid::config() const
{
	return _config;
}

bool Grid::isAlive(size_t i, size_t j) const
{
	return this->at(i, j).isAlive();
}

Grid::~Grid()
{
}
