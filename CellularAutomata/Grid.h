#include "FastMatrix.h"
#include "Cell.h"
#include "Config.h"

#pragma once
class Grid
{
public:
	Grid(Config config);
	inline vector size() const { return{ _grid.row(),_grid.col() }; }
	inline bool isAlive(size_t i, size_t j) const;
	~Grid();
private:
	FastMatrix<Cell> _grid;
	Config _config;
};

