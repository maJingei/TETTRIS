#include"BasicFunc.h"
#include"goto.h"
#include"Block.h"
#include"map.h"
#include<conio.h>
#include<iostream>
using namespace std;

extern char _Gmap[MAPHEIGHT][MAPWIDTH];
extern char _GOpeningMenu[OPNEMENUHEIGHT][OPENMENUWIDTH];
double GFALLSPEED = 0.5;

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
			if (b.BlockLandingCheck(b))
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

					if (key == 'c')
					{
						b.Rotate();
						b.BlockDraw();
					}

					if (key == ' ')
					{
						b.Move(0, 0);
						b.HardLanding();
						break;
					}


				}
				if (double(end - start) / CLOCKS_PER_SEC == GFALLSPEED)
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
	int MenuSelect = 0;
	int MenuPointY = 20;
	for (int i = 0; i < OPNEMENUHEIGHT; i++)
	{
		gotoxy(15, 5 + i);
		for (int j = 0; j < OPENMENUWIDTH; j++)
		{
			char temp = _GOpeningMenu[i][j];
			if (temp == 1)
			{
				cout << "■";
			}
			else
				cout << " ";
		}
	}
	gotoxy(50, 20);
	cout << "게임 플레이";
	gotoxy(50, 21);
	cout << "게임 설정";
	gotoxy(50, 22);
	cout << "게임 종료";
	gotoxy(48, MenuPointY);
	cout << "▶";
	while (true)
	{
		key = _getch();
		if (key)
		{
			if (key == 224)
			{
				key = _getch();
				if (key == DOWN)
				{
					if (MenuSelect < 2)
					{
						MenuSelect++;
						gotoxy(48, MenuPointY);
						cout << " ";
						gotoxy(48, ++MenuPointY);
						cout << "▶";
					}
				}
				else if (key == UP)
				{
					if (MenuSelect > 0)
					{
						MenuSelect--;
						gotoxy(48, MenuPointY);
						cout << " ";
						gotoxy(48, --MenuPointY);
						cout << "▶";
					}
				}
			}
			else if (key == ENTER)
			{
				break;
			}
		}
	}
	switch (MenuSelect)
	{
	case 0:
		system("cls");
		printGameMap();
		break;
	case 1:
		system("cls");
		GameOption();
		printMenu();
		break;
	case 2:
		exit(1);
		break;
	default:
		break;
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
	Mapping();

	gotoxy(30, 3);
	cout << "spacebar : 착지";
	gotoxy(30, 4);
	cout << "<- -> : 좌우이동";
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
	int FillLinePy = 0;
	int FillLineCount = 0;
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
			FillLinePy = i;
			FillLineCount++;
		}
	}
	if (FillLineCount > 0)
	{
		for (int j = FillLinePy - 1; j > 1; j--)
		{
			for (int i = 1; i < MAPWIDTH - 1; i++)
			{
				_Gmap[j + FillLineCount][i] = _Gmap[j][i];
			}
		}
	}
}

void GameOption()
{
	while (true)
	{
		int key;
		gotoxy(50, 10);
		cout << " 블록 낙하 스피드 ◀ " << GFALLSPEED << " ▶";
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == LEFT)
			{
				if (GFALLSPEED > 0.2)
					GFALLSPEED -= 0.1;
				gotoxy(50, 10);
				cout << "                                             ";
			}
			else if (key == RIGHT)
			{
				if (GFALLSPEED < 1.0)
					GFALLSPEED += 0.1;
				gotoxy(50, 10);
				cout << "                                             ";
			}
		}
		else if (key == ENTER)
			break;
	}

}