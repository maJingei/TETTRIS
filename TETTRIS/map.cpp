#include"map.h"
#include"goto.h"
#include<iostream>
using namespace std;

char _Gmap[MAPHEIGHT][MAPWIDTH] = {
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void Mapping()
{
	int tempx = 0;
	int tempy = 0;
	for (int tempy = 0; tempy < MAPHEIGHT; tempy++)
	{
		gotoxy(tempx, tempy);
		for (int tempx = 0; tempx < MAPWIDTH; tempx++)
		{
			char temp = _Gmap[tempy][tempx];
			if (temp == 1) // 벽
				cout << "▣";
			else if (temp == 2) //사용자의 입력을 떠난 쌓인 블록
				cout << "■";
			else if (temp == 3) //사용자의 조종을 받고있는 블록
				cout << "■";
			else if (temp == 4) // 테트리스 그림자
				cout << "□";
			else
				cout << " ";
		}
	}
	//switch (random)
	//{
	//case 1: // 네모 모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX + 1, EARY);
	//	Blockpt[2].setPoint(EARX, EARY + 1);
	//	Blockpt[3].setPoint(EARX + 1, EARY + 1);
	//	break;
	//case 2: // 뻐큐모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX, EARY + 1);
	//	Blockpt[2].setPoint(EARX - 1, EARY + 1);
	//	Blockpt[3].setPoint(EARX + 1, EARY + 1);
	//	break;
	//case 3: // 1자 모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX, EARY + 1);
	//	Blockpt[2].setPoint(EARX, EARY + 2);
	//	Blockpt[3].setPoint(EARX, EARY + 3);
	//	break;
	//case 4: // ㅡ자 모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX + 1, EARY);
	//	Blockpt[2].setPoint(EARX + 2, EARY);
	//	Blockpt[3].setPoint(EARX - 1, EARY);
	//	break;
	//case 5: // 꼬불모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX + 1, EARY);
	//	Blockpt[2].setPoint(EARX, EARY + 1);
	//	Blockpt[3].setPoint(EARX - 1, EARY + 1);
	//	break;
	//case 6: // L자 모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX, EARY + 1);
	//	Blockpt[2].setPoint(EARX, EARY + 2);
	//	Blockpt[3].setPoint(EARX + 1, EARY + 2);
	//	break;
	//case 7:// 반대 L자 모양
	//	Blockpt[0].setPoint(EARX, EARY);
	//	Blockpt[1].setPoint(EARX, EARY + 1);
	//	Blockpt[2].setPoint(EARX, EARY + 2);
	//	Blockpt[3].setPoint(EARX - 1, EARY + 2);
	//	break;
	//default:
	//	break;
	//}
}