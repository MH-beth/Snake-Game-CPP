#pragma once
#ifndef SNAKE_H
#define SNAKE_h

#include <Windows.h>

#define WIDTH 50
#define HEIGHT 25

class Snake {
private:
	COORD pos; // position Coordonites
	int len; // snake length 
	int vel; // Vellocity or speed of the snake
	char direction;// direction of the snake 

public:
	Snake(COORD pos, int vel);
	void changeDirection(char dir);
	void moveSnake();
	COORD getPosition();
	bool eaten(COORD food_pos);
	void grow();
	bool collided();
	int getLen();
};




#endif // SNAKE_H

