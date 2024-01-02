#include"Block.h"
#include"goto.h"
#include"map.h"
#include<iostream>
using namespace std;

extern char _Gmap[MAPHEIGHT][MAPWIDTH];

Block::Block()
{
	random = rand() % 7 + 1;
	switch (random)
	{
	case 1: // 네모 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX + 1, EARY);
		Blockpt[2].setPoint(EARX, EARY+1);
		Blockpt[3].setPoint(EARX+1, EARY+1);
		break;
	case 2: // 뻐큐모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX , EARY + 1);
		Blockpt[2].setPoint(EARX - 1, EARY + 1);
		Blockpt[3].setPoint(EARX + 1, EARY + 1);
		break;
	case 3: // 1자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX, EARY + 1);
		Blockpt[2].setPoint(EARX, EARY + 2);
		Blockpt[3].setPoint(EARX, EARY + 3);
		break;
	case 4: // ㅡ자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX + 1, EARY);
		Blockpt[2].setPoint(EARX + 2, EARY);
		Blockpt[3].setPoint(EARX - 1, EARY);
		break;
	case 5: // 꼬불모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX + 1, EARY);
		Blockpt[2].setPoint(EARX, EARY + 1);
		Blockpt[3].setPoint(EARX - 1, EARY + 1);
		break;
	case 6: // L자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX, EARY + 1);
		Blockpt[2].setPoint(EARX, EARY + 2);
		Blockpt[3].setPoint(EARX + 1, EARY + 2);
		break;
	case 7:// 반대 L자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX, EARY + 1);
		Blockpt[2].setPoint(EARX, EARY + 2);
		Blockpt[3].setPoint(EARX - 1, EARY + 2);
		break;
	default:
		break;
	}
}


void Block::BlockDraw()
{
	// 아래는 그림자 블럭 draw
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		ShadowBlockpt[i] = Blockpt[i];
	}

	while (_Gmap[ShadowBlockpt[0].getY() + 1][ShadowBlockpt[0].getX()] < 1 &&
		_Gmap[ShadowBlockpt[1].getY() + 1][ShadowBlockpt[1].getX()] < 1 &&
		_Gmap[ShadowBlockpt[2].getY() + 1][ShadowBlockpt[2].getX()] < 1 &&
		_Gmap[ShadowBlockpt[3].getY() + 1][ShadowBlockpt[3].getX()] < 1)
	{
		ShadowBlockpt[0].MoveY(1);
		ShadowBlockpt[1].MoveY(1);
		ShadowBlockpt[2].MoveY(1);
		ShadowBlockpt[3].MoveY(1);
	}
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		_Gmap[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()] = 3;
	}
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		char temp = _Gmap[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()];
		gotoxy(ShadowBlockpt[i].getX(), ShadowBlockpt[i].getY());
		if (temp == 3)
		{
			cout << "□";
		}
	}

	// 아래는 블럭 draw
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		_Gmap[Blockpt[i].getY()][Blockpt[i].getX()] = 2;
	}
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		char temp = _Gmap[Blockpt[i].getY()][Blockpt[i].getX()];
		gotoxy(Blockpt[i].getX(), Blockpt[i].getY());
		if (temp == 2)
		{
			cout << "■";
		}
	}
}

void Block::Move(int px, int py)
{
	// 기존의 블럭 삭제
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		gotoxy(Blockpt[i].getX(), Blockpt[i].getY());
		char temp = _Gmap[Blockpt[i].getY()][Blockpt[i].getX()];
		if (temp == 2)
		{
			cout << " ";
			_Gmap[Blockpt[i].getY()][Blockpt[i].getX()] = 0;
		}
	}
	// 그림자 블럭 삭제
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		gotoxy(ShadowBlockpt[i].getX(),ShadowBlockpt[i].getY());
		char shadowTemp = _Gmap[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()];
		if (shadowTemp == 3)
		{
			cout << " ";
			_Gmap[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()] = 0;
		}
	}
	if (_Gmap[Blockpt[0].getY()][Blockpt[0].getX() + px] > 0 ||
		_Gmap[Blockpt[1].getY()][Blockpt[1].getX() + px] > 0 ||
		_Gmap[Blockpt[2].getY()][Blockpt[2].getX() + px] > 0 ||
		_Gmap[Blockpt[3].getY()][Blockpt[3].getX() + px] > 0)
	{
		for (int i = 0; i < BLOCKSIZE; i++)
			Blockpt[i].MoveX(0);
	}
	else
	{
		for (int i = 0; i < BLOCKSIZE; i++)
		{
			Blockpt[i].MoveX(px);
			Blockpt[i].MoveY(py);
		}
	}
}

bool Block::BlockLandingCheck(Block b, int random)
{
	// 블럭에 따라 다른 랜딩 조건
	switch (random)
	{
		// 네모 블럭
	case 1:
		if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 || _Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 || _Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// 뻐큐블럭
	case 2:
		if (_Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 1 || _Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 2 || _Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// 1자 블럭
	case 3:
		if (_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// ㅡ자 블럭
	case 4:
		if (_Gmap[b.Blockpt[0].getY() + 1][b.Blockpt[0].getX()] == 1 || _Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 1 ||
			_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 || _Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[0].getY() + 1][b.Blockpt[0].getX()] == 2 || _Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 2 ||
			_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 || _Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// 꼬불 블럭
	case 5:
		if (_Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 1 || _Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 2 || _Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// L자 블럭
	case 6:
		if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
		// 반대 L자 블럭
	case 7:
		if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
		{
			return true;
		}
		else if (_Gmap[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 ||
			_Gmap[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
		{
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void Block::HardLanding()
{
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		Blockpt[i] = ShadowBlockpt[i];
	}
}

void Block::Rotate()
{
	int index = 0;
	int X = Blockpt[0].getX() - 1;
	int Y = Blockpt[0].getY() + 1;
	Point TempPt[BLOCKSIZE];

	for (int i = 0; i < BLOCKSIZE - 1; i++)
	{
		for (int j = 0; j < BLOCKSIZE - 1; j++)
		{
			char temp = _Gmap[Y - j][X + i];
			if (temp == 2)
			{
				TempPt[index++].setPoint(X + j, Y - 2 + i);
			}
		}
	}
	Move(0, 0);
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		Blockpt[i] = TempPt[i];
	}
}