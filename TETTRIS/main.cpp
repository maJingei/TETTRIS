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
		Map m; // ���� ������ �� �ٽ� �����ϸ� ���� �ʱ�ȭ �Ǿ�� �ϹǷ� Ŭ������ ����
		printMenu(m);
		system("cls");
	}
}