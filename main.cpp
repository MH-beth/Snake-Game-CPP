/*
Copiright and all rights reserver MH15o
Check the licence file for more information
*/

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <string>

// Other Includes
#include "Snake.h"
#include "Food.h"
// end iNCLUDES

// Macros : 
#define WIDTH 50
#define HEIGHT 25

// end Macros

using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);
Food food;

int x = 10, y = 10, z = 1;
int score = 0;
int len = 1;

void board()
{
	COORD snakePos = snake.getPosition();
	COORD foodPos = food.getPos();
	std::cout << "Score : " << score << std::endl;
	for (int i = 0; i < HEIGHT; i++)
	{
		std::cout << "`\t\t#";
		for (int j = 0; j < WIDTH-2; j++)
		{
			if (i == 0 || i == HEIGHT - 1)
			{
				std::cout << "#";
			}
			else if (i == snakePos.Y && j == snakePos.X)
			{
				std::cout << "0";
			}
			else if (i == foodPos.Y && j == foodPos.X) 
			{
				std::cout << "@";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "#" << std::endl;
	}
}

int main()
{
	srand(time(NULL));	
	bool game = false;
	std::string command;
	bool gameOver = false;
	std::cout << "\t\t Welcome to snake Game " << std::endl;
	std::cout << "1.Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cin >> command;
	if (command == "1")
	{
		game = true;
		system("cls");
	}
	else
	{
		return 0;
	}

	while (game)
	{
		board();
		if (_kbhit()) // if a key in the key board is hit
		{
			switch (_getch())
			{
				// AZERTY Keyboard
			case 'z':
				snake.changeDirection('u');
				break;
			
			case 'd':
				snake.changeDirection('r');
				break;
			case 's':
				snake.changeDirection('d');
				break;
			case 'q':
				snake.changeDirection('l');
				break;
			}
			snake.moveSnake();
			if (snake.eaten(food.getPos()))
			{
				food.gen_Food();
				snake.grow();
				score++;
			}

			if (snake.collided())
			{
				game = false;
				gameOver = true;
			}
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	}
	if (gameOver)
	{
		system("CLS");
		std::cout << "GameOver !" << std::endl;
		std::cout << "Final Score : " << score << std::endl;
		system("PAUSE");
	}
	else
	{
		return 0;
	}
}
