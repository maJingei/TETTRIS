#pragma once
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#include"map.h"



class GameUtillFunc
{
public:
	static void run(Map& m);
	static void FillLineClear(Map& m);
	static bool EndGame(Map& m);
	static void gotoxy(int x, int y);
	static void HIdeCursor();
};
