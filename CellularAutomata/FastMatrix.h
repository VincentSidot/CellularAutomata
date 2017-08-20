#pragma once
#include <Windows.h>
#include <vector>
#include <initializer_list>
#include <cassert>
#include "FastCopy.h"

template<class T>
class FastMatrix
{
public:
	FastMatrix(size_t row,size_t col) : _row{ row }, _col{ col }
	{
		_data = new T[row*col];
	}
	FastMatrix(size_t row, size_t col, T defval) : _row{ row }, _col{ col }
	{
		_data = new T[row*col];
		for (size_t i = 0; i < (row*col); i++)
			_data[i] = defval;
	}
	FastMatrix(FastMatrix<T> const &oth) : _row{ oth.row() }, _col{ oth.col() }
	{
		_data = new T[oth.row() * oth.col()];
		FastCopy::threadMemCpy(oth.data(), _data, oth.row()*oth.col() * sizeof(T));
	}
	~FastMatrix()
	{
		if(_data != nullptr)
			delete[] _data;
	}

	inline size_t row() const { return _row; }
	inline size_t col() const { return _col; }
	inline T* data() const { return _data; }
	inline void Fill(std::vector<T> const &vec)
	{
		this->Fill(vec.data(), vec.size());
	}
	inline void Fill(T* dataarray, size_t size)
	{
		FastCopy::threadMemCpy(dataarray,_data,min(_row*_col,size) * sizeof(T))
	}
	inline void Fill(std::initializer_list<T> const &init)
	{
		size_t i = 0;
		for (auto &val : init)
		{
			if (i < (_row*_col))
				_data[i++] = val;
			else
				break;
		}
		return;
	}
	inline void Fill(FastMatrix<T> const &m)
	{
		if (this->size() == m.size())
			FastCopy::threadMemCpy(m.data(), _data, this->size() * sizeof(T));
	}
	inline T& operator()(size_t i, size_t j)
	{
		assert(i*j <= _row*_col);
		return *(_data + i + _col * j);
	}
	inline const T& operator()(size_t i, size_t j) const
	{
		assert(i*j <= _row*_col);
		return *(_data + i + _col * j);
	}
	inline T& operator=(FastMatrix<T> const &m)
	{
		this->realoc(m.row(), m.col());
		this->Fill(m);
		return *this;
	}
	inline T at(size_t i, size_t j) const
	{
		assert(i*j <= _row*_col);
		return *(_data + i + _col * j);
	}
	inline void set(size_t i, size_t j, T val)
	{
		assert(i*j <= _row*_col);
		*(_data + i + _col * j) = val;
	}
	inline size_t size() const { return _row*_col; }
	inline void reset()
	{
		_row =		  0;
		_col =	 	  0;
		delete[]  _data;
		_data = nullptr;
	}
	inline void realoc(size_t row, size_t col)
	{
		this->reset();
		_row = row;
		_col = col;
		_data = new T[row*col];
	}
	inline void threadedCopy(FastMatrix<T> const &othr)
	{
		delete[] _data;
		_col = othr.col();
		_row = othr.row();
		_data = new T[(size_t)(_row*_col)];
		FastCopy::threadMemCpy(othr.data(), _data, _col*_row * sizeof(T));
		return;
	}
protected:
	size_t _row, _col;
	T* _data;
};

namespace FastMatrixUtility
{
	template<class T>
	inline void Copy(FastMatrix<T> &dst, FastMatrix<T> const &src)
	{
		dst.threadedCopy(src);
		return;
	}
	template<class T>
	inline void Reset(FastMatrix<T> &m)
	{
		m.reset();
		return;
	}
};


