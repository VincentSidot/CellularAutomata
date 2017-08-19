#include <iostream>
#include <Windows.h>
#include "FastMatrix.hpp"


int main(int argc, char** argv)
{
	SetConsoleTitleA("Cellular automata");
//-------------------------------------------------------------------
	
	FastMatrix<int> m1(2, 5,2);
	FastMatrix<int> m2(2, 5,2);
	m1.Fill({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 });

//-------------------------------------------------------------------

	std::cout << "Printing m1 : ";
	for (size_t i = 0; i < (m1.row()*m1.col()); i++)
	{
		if (i%m1.col() == 0)
			std::cout << std::endl;
		std::cout << m1.data()[i] << " ";
	}
	std::cout << std::endl << std::endl << "Printing m2 : ";
	for (size_t i = 0; i < (m2.row()*m2.col()); i++)
	{
		if (i%m2.col() == 0)
			std::cout << std::endl;
		std::cout << m2.data()[i] << " ";
	}
	std::cout << std::endl;
//-------------------------------------------------------------------
	

//-------------------------------------------------------------------

	std::cout << "Printing m1 : ";
	for (size_t i = 0; i < (m1.row()*m1.col()); i++)
	{
		if (i%m1.col() == 0)
			std::cout << std::endl;
		std::cout << m1.data()[i] << " ";
	}
	std::cout << std::endl << std::endl << "Printing m2 : ";
	for (size_t i = 0; i < (m2.row()*m2.col()); i++)
	{
		if (i%m2.col() == 0)
			std::cout << std::endl;
		std::cout << m2.data()[i] << " ";
	}

//-------------------------------------------------------------------
	std::cin.get();
	return 0;
}