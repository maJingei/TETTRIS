#include "goto.h"
#include "map.h"
#include "Block.h"
#include "BasicFunc.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

extern char _Gmap[MAPHEIGHT][MAPWIDTH];


int main()
{
	srand((unsigned)time(NULL));
	HIdeCursor();
	printMenu();
}