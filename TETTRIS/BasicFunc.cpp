#include"BasicFunc.h"
#include"goto.h"
#include"Block.h"
#include"map.h"
#include<conio.h>
#include<iostream>
#define LEFT 75
#define RIGHT 77
#define FALLSPEED 0.1
using namespace std;

extern char _Gmap[MAPHEIGHT][MAPWIDTH];

void run()
{
	while (true)
	{
		if (EndGame())
		{
			break;
		}
		Block b;
		Mapping();
		while (true)
		{
			b.BlockDraw();
			if (b.BlockLandingCheck(b, b.random))
			{
				break;
			}
			clock_t start = clock();
			while (true)
			{
				clock_t end = clock();
				int movekey = 0;
				if (_kbhit())
				{
					movekey = _getch();
					if (movekey == 224)
					{
						movekey = _getch();
					}

					if (movekey == ' ')
					{
						b.Move(0, 0);
						b.HardLanding();
						break;
					}

					if (movekey == LEFT)
					{
						b.Move(-1, 0);
						b.BlockDraw();
					}

					else if (movekey == RIGHT)
					{
						b.Move(1, 0);
						b.BlockDraw();
					}
				}
				if (double(end - start) / CLOCKS_PER_SEC == FALLSPEED)
				{
					b.Move(0, 1);
					break;
				}
			}
		}
	}
}

void printMenu()
{
	int key;
	gotoxy(50, 10);
	cout << "any key press";
	key = _getch();
	if (key)
	{
		system("cls");
		printGameMap();
	}
}

bool EndGame()
{
	for (int i = 1; i < MAPWIDTH; i++)
	{
		if (_Gmap[EARY][i] == 2)
		{
			return true;
		}
	}
	return false;
}

void printGameMap()
{
	int key;
	int tempx = 0;
	int tempy = 0;
	for (int tempy = 0; tempy < MAPHEIGHT; tempy++)
	{
		gotoxy(tempx, tempy);
		for (int tempx = 0; tempx < MAPWIDTH; tempx++)
		{
			char temp = _Gmap[tempy][tempx];
			if (temp == 1)
				cout << "¢Ã";
			else if (temp == 2)
				cout << "¡á";
			else
				cout << " ";
		}
	}

	gotoxy(30, 3);
	cout << "spacebar : ÂøÁö";
	gotoxy(30, 4);
	cout << "<- -> : ÁÂ¿ìÀÌµ¿";
	gotoxy(0, 10);
	cout << "any key press, Game Start";
	key = _getch();
	if (key)
	{
		gotoxy(0, 10);
		cout << "                                           ";
		run();
	}
}