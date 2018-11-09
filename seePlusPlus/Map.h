#pragma once
#include "main.h"

class Map 
{
public:
	Map();
	Map(unsigned int x, unsigned int y);
	int getPosition(unsigned int x, unsigned int y);
	~Map();
private:
	int * mapMatrix;
	unsigned int x;
	unsigned int y;
};