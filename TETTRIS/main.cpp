#include "goto.h"
#include "Block.h"
#include "BasicFunc.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


int main()
{
	srand((unsigned)time(NULL));
	HIdeCursor();
	while (true)
	{
		Map m; // 게임 오버된 후 다시 시작하면 맵이 초기화 되어야 하므로 클래스로 선언
		printMenu(m);
		system("cls");
	}
}