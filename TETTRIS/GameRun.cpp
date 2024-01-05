#include"GameUtillFunc.h"
#include"Block.h"
#include<conio.h>
#include<iostream>
using namespace std;

extern char _GOpeningMenu[OPNEMENUHEIGHT][OPENMENUWIDTH];
double GFALLSPEED = 0.5;

void GameUtillFunc::run(Map& m)
{
	while (true)
	{
		if (GameUtillFunc::EndGame(m))
		{
			GameUtillFunc::gotoxy(MAPINITX+ 8, MAPINITY + 10);
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
		GameUtillFunc::FillLineClear(m);
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
  						if (key == LEFT) // 왼쪽 방향키 입력시 왼쪽으로 이동
						{
							b.Move(m,-1, 0);
							b.BlockDraw(m);
						}

						else if (key == RIGHT) // 오른쪽 방향키 입력시 오른쪽으로 이동
						{
							b.Move(m,1, 0);
							b.BlockDraw(m);
						}
					}

					if (key == 'c' || key == 'C') // c입력시 블록 회전
					{
						b.Rotate(m);
						b.BlockDraw(m);
					}

					if (key == ' ') // 스페이스바 입력시 착지
					{
						b.Move(m,0, 0);
						b.HardLanding();
						break;
					}
					
					if (key == 'p' || key == 'P') // p 입력시 일시정지
					{
						GameUtillFunc::gotoxy(MAPINITX + 8, MAPINITY + 10);
						cout << "pause";
						while (true)
						{
							int pausekey;
							pausekey = _getch();
							if (pausekey == 'p' || key == 'P')
								break;
						}
						GameUtillFunc::gotoxy(MAPINITX + 8, MAPINITY + 10);
						cout << "     ";
					}


				}
				if (static_cast<double>(end - start) / CLOCKS_PER_SEC > GFALLSPEED) // Clock시간의 차가 낙하 속도 값보다 커지면 바로 한칸 아래로 이동 
				{
					b.Move(m,0, 1);
					break;
				}
			}
		}
	}
}

void printGameMap(Map& m)
{
	int key;
	Mapping(m);

	GameUtillFunc::gotoxy(MAPINITX + 40, MAPINITY + 10);
	cout << "spacebar : 착지";
	GameUtillFunc::gotoxy(MAPINITX + 40, MAPINITY + 12);
	cout << "<- -> : 좌우이동";
	GameUtillFunc::gotoxy(MAPINITX + 40, MAPINITY + 14);
	cout << "c : 블럭 회전";
	GameUtillFunc::gotoxy(MAPINITX + 40, MAPINITY + 16);
	cout << "p : 일시정지";
	GameUtillFunc::gotoxy(MAPINITX, MAPINITY + 10);
	cout << "any key press, Game Start";
	key = _getch();
	if (key)
	{
		GameUtillFunc::gotoxy(MAPINITX, MAPINITY + 10);
		cout << "                                    ";
		GameUtillFunc::run(m);
	}
}