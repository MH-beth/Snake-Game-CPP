#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <Windows.h>
#include <cstdlib>
#include <ctime>

#define WIDTH 50
#define HEIGHT 25

class Food
{
private:
	COORD pos; // food Position

public:
	Food();
	void gen_Food();
	COORD getPos();
};

#endif // FOOD_H
