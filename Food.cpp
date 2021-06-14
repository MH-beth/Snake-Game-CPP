#include "Food.h"


Food::Food()
{
	this->gen_Food();
}

void Food::gen_Food()
{
	this->pos.X = rand() % WIDTH - 2;
	this->pos.Y = rand() % HEIGHT - 2;
}

COORD Food::getPos()
{
	return this->pos;
}