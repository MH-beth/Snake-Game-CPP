#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
	this->pos = pos;
	this->vel = vel;
	this->len = 0;// intial snake length set to 1
	this->direction = 'n';// initial direction set to "none"
}

void Snake::changeDirection(char dir)
{
	this->direction = dir;
}

void Snake::moveSnake()
{
	switch (this->direction)
	{
	case 'u': // in case of the snake going up
		this->pos.Y -= this->vel;
		break;
	case 'd': // in case of going down
		this->pos.Y += this->vel;
		break;
	case 'l':// in case of going left
		this->pos.X -= this->vel;
		break;
	case 'r': // in case of going Right
		this->pos.X += this->vel;
		break;
	}
}

COORD Snake::getPosition()
{
	return this->pos;
}

bool Snake::eaten(COORD food_pos)
{
	if (food_pos.X == this->pos.X && food_pos.Y == this->pos.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Snake::grow()
{
	this->len++;
}

bool Snake::collided()
{
	if (this->pos.X < 1 || this->pos.X > WIDTH || this->pos.Y <1 || this->pos.Y >HEIGHT) return true;
	else return false;
}
