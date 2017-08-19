#include "Grid.h"


Grid::Grid(Config config) : _config{ config }, _grid{config.grid().x/config.cell().x,config.grid().y / config.cell().y}
{
	for (size_t i = 0; i < _grid.row(); i++)
	{
		for (size_t j = 0; j < _grid.col(); j++)
		{
			_grid(i, j) = Cell(i, j, _config, false);
		}
	}
}

inline bool Grid::isAlive(size_t i, size_t j) const
{
	_grid.at(i, j).isAlive();
}

Grid::~Grid()
{
}
