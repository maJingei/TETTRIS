#include"GameUtillFunc.h"
#include"Block.h"
#include<iostream>
#include<conio.h>
using namespace std;
extern double GFALLSPEED;

char _GOpeningMenu[OPNEMENUHEIGHT][OPENMENUWIDTH] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
	{1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,1,1,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,1,1,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,1},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
	{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
};

void Mapping(Map& m)
{
	int tempx = 0, tempy = 0;
	int CursortempX = MAPINITX;
	int CursortempY = MAPINITY;
	for (tempy = 0; tempy < MAPHEIGHT; tempy++)
	{
		GameUtillFunc::GameUtillFunc::gotoxy(CursortempX, CursortempY);
		for (tempx = 0; tempx < MAPWIDTH; tempx++)
		{
			char temp = m._map[tempy][tempx];
			if (temp == 1) // ��
				cout << "��";
			else if (temp == 2) //������� �Է��� ���� ���� ���
				cout << "��";
			else if (temp == 3) //������� ������ �ް��ִ� ���
				cout << "��";
			else if (temp == 4) // ��Ʈ���� �׸���
				cout << "��";
			else
				cout << " ";
		}
		CursortempY++;
	}
}

void printMenu(Map& m)
{
	int key;
	int MenuSelect = 0;
	int MenuPointY = 20;
	for (int i = 0; i < OPNEMENUHEIGHT; i++)
	{
		GameUtillFunc::gotoxy(15, 5 + i);
		for (int j = 0; j < OPENMENUWIDTH; j++)
		{
			char temp = _GOpeningMenu[i][j];
			if (temp == 1)
			{
				cout << "��";
			}
			else
				cout << " ";
		}
	}
	GameUtillFunc::gotoxy(40, 18);
	cout << "�� �Ʒ� ����Ű�� EnterŰ�� �����ϼ��� !";
	GameUtillFunc::gotoxy(50, 20);
	cout << "���� �÷���";
	GameUtillFunc::gotoxy(50, 21);
	cout << "���� ����";
	GameUtillFunc::gotoxy(50, 22);
	cout << "���� ����";
	GameUtillFunc::gotoxy(48, MenuPointY);
	cout << "��";
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
						GameUtillFunc::gotoxy(48, MenuPointY);
						cout << " ";
						GameUtillFunc::gotoxy(48, ++MenuPointY);
						cout << "��";
					}
				}
				else if (key == UP)
				{
					if (MenuSelect > 0)
					{
						MenuSelect--;
						GameUtillFunc::gotoxy(48, MenuPointY);
						cout << " ";
						GameUtillFunc::gotoxy(48, --MenuPointY);
						cout << "��";
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
		printGameMap(m);
		break;
	case 1:
		system("cls");
		printGameOption();
		printMenu(m);
		break;
	case 2:
		exit(0);
		break;
	default:
		break;
	}
}

void printGameOption()
{
	while (true)
	{
		int key;
		GameUtillFunc::gotoxy(50, 10);
		cout << " ��� ���� ���ǵ� �� " << (GFALLSPEED * 10.0) << " ��";
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == LEFT)
			{
				if (GFALLSPEED > 0.2)
					GFALLSPEED -= 0.1;
				GameUtillFunc::gotoxy(50, 10);
				cout << "                                             ";
			}
			else if (key == RIGHT)
			{
				if (GFALLSPEED < 1.0)
					GFALLSPEED += 0.1;
				GameUtillFunc::gotoxy(50, 10);
				cout << "                                             ";
			}
		}
		else if (key == ENTER)
			break;
	}

}


