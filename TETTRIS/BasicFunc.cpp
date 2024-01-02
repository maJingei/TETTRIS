#include"BasicFunc.h"
#include"goto.h"
#include"Block.h"
#include"map.h"
#include<conio.h>
#include<iostream>
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
		FillLineClear();
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
				int key = 0;
				if (_kbhit())
				{
					key = _getch();
					if (key == 224)
					{
						key = _getch();
					}

					if (key == ' ')
					{
						b.Move(0, 0);
						b.HardLanding();
						break;
					}

					if (key == 'c')
					{
						b.Rotate();
						b.BlockDraw();
					}

					if (key == LEFT)
					{
						b.Move(-1, 0);
						b.BlockDraw();
					}

					else if (key == RIGHT)
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

void FillLineClear()
{
	int flag = 0;
	int FillLinePy = 0;
	for (int i = MAPHEIGHT - 1; i > 1; i--)
	{
		int count = 0;
		for (int j = 1; j < MAPWIDTH - 1; j++)
		{
			if (_Gmap[i][j] == 2)
				count++;
			else break;
		}
		if (count == MAPWIDTH - 2)
		{
			flag = 1;
			FillLinePy = i;
			break;
		}
	}
	if (flag == 1)
	{
		for (int j = FillLinePy - 1; j > 1; j--)
		{
			for (int i = 1; i < MAPWIDTH - 1; i++)
			{
				_Gmap[j + 1][i] = _Gmap[j][i];
			}
		}
	}
}