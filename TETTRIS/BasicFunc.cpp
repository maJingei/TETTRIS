#include"BasicFunc.h"
#include"goto.h"
#include"Block.h"
#include<conio.h>
#include<iostream>
using namespace std;

extern char _GOpeningMenu[OPNEMENUHEIGHT][OPENMENUWIDTH];
double GFALLSPEED = 0.5;

void run(Map& m)
{
	while (true)
	{
		if (EndGame(m))
		{
			gotoxy(MAPINITX+ 8, MAPINITY + 10);
			cout << "GAME OVER";
			while (true)
			{
				int endkey;
				endkey = _getch();
				if (endkey)
					break;
			}
			break;
		}
		FillLineClear(m);
		Block b;
		Mapping(m);
		while (true)
		{
			b.BlockDraw(m);
			if (b.BlockLandingCheck(m,b))
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
  						if (key == LEFT) // ���� ����Ű �Է½� �������� �̵�
						{
							b.Move(m,-1, 0);
							b.BlockDraw(m);
						}

						else if (key == RIGHT) // ������ ����Ű �Է½� ���������� �̵�
						{
							b.Move(m,1, 0);
							b.BlockDraw(m);
						}
					}

					if (key == 'c' || key == 'C') // c�Է½� ��� ȸ��
					{
						b.Rotate(m);
						b.BlockDraw(m);
					}

					if (key == ' ') // �����̽��� �Է½� ����
					{
						b.Move(m,0, 0);
						b.HardLanding();
						break;
					}
					
					if (key == 'p' || key == 'P') // p �Է½� �Ͻ�����
					{
						gotoxy(MAPINITX + 8, MAPINITY + 10);
						cout << "pause";
						while (true)
						{
							int pausekey;
							pausekey = _getch();
							if (pausekey == 'p' || key == 'P')
								break;
						}
						gotoxy(MAPINITX + 8, MAPINITY + 10);
						cout << "     ";
					}


				}
				if (double(end - start) / CLOCKS_PER_SEC > GFALLSPEED) // Clock�ð��� ���� ���� �ӵ� ������ Ŀ���� �ٷ� ��ĭ �Ʒ��� �̵� 
				{
					b.Move(m,0, 1);
					break;
				}
			}
		}
	}
}

bool EndGame(Map& m)
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

void printGameMap(Map& m)
{
	int key;
	Mapping(m);

	gotoxy(MAPINITX + 40, MAPINITY + 10);
	cout << "spacebar : ����";
	gotoxy(MAPINITX + 40, MAPINITY + 12);
	cout << "<- -> : �¿��̵�";
	gotoxy(MAPINITX + 40, MAPINITY + 14);
	cout << "c : �� ȸ��";
	gotoxy(MAPINITX + 40, MAPINITY + 16);
	cout << "p : �Ͻ�����";
	gotoxy(MAPINITX, MAPINITY + 10);
	cout << "any key press, Game Start";
	key = _getch();
	if (key)
	{
		gotoxy(MAPINITX, MAPINITY + 10);
		cout << "                                    ";
		run(m);
	}
}

void FillLineClear(Map& m)
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

