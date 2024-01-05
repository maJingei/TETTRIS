#include"GameUtillFunc.h"
#include"Block.h"
#include<iostream>
#include<Windows.h>
using namespace std;

void GameUtillFunc::FillLineClear(Map& m)
{
	int FillLinePy = 0;
	int FillLineCount = 0;
	for (int i = MAPHEIGHT - 1; i > 1; i--)
	{
		int count = 0;
		for (int j = 1; j < MAPWIDTH - 1; j++)
		{
			if (m._map[i][j] == 2)
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
				m._map[j + FillLineCount][i] = m._map[j][i];
			}
		}
	}
}

bool GameUtillFunc::EndGame(Map& m)
{
	for (int i = 1; i < MAPWIDTH; i++)
	{
		if (m._map[EARY][i] == 2)
		{
			return true;
		}
	}
	return false;
}

void GameUtillFunc::gotoxy(int x, int y)
{
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}


void GameUtillFunc::HIdeCursor()
{
	CONSOLE_CURSOR_INFO cursor = { 0, };
	cursor.dwSize = 1;
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}