#include "Map.h"

Map::Map() 
{
	this->x = 64;
	this->y = 64;
	try 
	{
		mapMatrix = new int[x, y]();
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}

Map::Map(unsigned int x, unsigned int y) 
{
	this->x = x;
	this->y = y;
	mapMatrix = new int[x, y]();
}

int Map::getPosition(unsigned int x, unsigned int y) 
{
	if ((x >= this->x) || (y >= this->y)) 
	{
		throw std::out_of_range("Out of bounds");
	}
	return mapMatrix[x, y];
}

Map::~Map() 
{
	delete mapMatrix;
}