#include"GameUtillFunc.h"
#include "Block.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


int main()
{
	srand((unsigned)time(NULL));
	GameUtillFunc::HIdeCursor();
	while (true)
	{
		Map m; // ���� ������ �� �ٽ� �����ϸ� ���� �ʱ�ȭ �Ǿ�� �ϹǷ� Ŭ������ ����
		printMenu(m);
		system("cls");
	}
}