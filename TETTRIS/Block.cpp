#include"Block.h"
#include"GameUtillFunc.h"
#include<iostream>
using namespace std;

Block::Block()
{
	_random = rand() % 8 + 1;
	switch (_random)
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
	case 6: // 반대 꼬불모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX - 1, EARY);
		Blockpt[2].setPoint(EARX, EARY + 1);
		Blockpt[3].setPoint(EARX + 1, EARY + 1);
		break;
	case 7: // L자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX, EARY + 1);
		Blockpt[2].setPoint(EARX, EARY + 2);
		Blockpt[3].setPoint(EARX + 1, EARY + 2);
		break;
	case 8:// 반대 L자 모양
		Blockpt[0].setPoint(EARX, EARY);
		Blockpt[1].setPoint(EARX, EARY + 1);
		Blockpt[2].setPoint(EARX, EARY + 2);
		Blockpt[3].setPoint(EARX - 1, EARY + 2);
		break;
	default:
		break;
	}
}


void Block::BlockDraw(Map& m)
{
	// 아래는 그림자 블럭 draw
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		ShadowBlockpt[i] = Blockpt[i];
	}

	while (m._map[ShadowBlockpt[0].getY() + 1][ShadowBlockpt[0].getX()] < 1 &&
		m._map[ShadowBlockpt[1].getY() + 1][ShadowBlockpt[1].getX()] < 1 &&
		m._map[ShadowBlockpt[2].getY() + 1][ShadowBlockpt[2].getX()] < 1 &&
		m._map[ShadowBlockpt[3].getY() + 1][ShadowBlockpt[3].getX()] < 1)
	{
		ShadowBlockpt[0].MoveY(1);
		ShadowBlockpt[1].MoveY(1);
		ShadowBlockpt[2].MoveY(1);
		ShadowBlockpt[3].MoveY(1);
	}
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		m._map[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()] = 4;
	}
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		char temp = m._map[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()];
		GameUtillFunc::gotoxy(MAPINITX+ShadowBlockpt[i].getX(), MAPINITY+ShadowBlockpt[i].getY());
		if (temp == 4)
		{
			cout << "□";
		}
	}

	// 아래는 블럭 draw
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		m._map[Blockpt[i].getY()][Blockpt[i].getX()] = 3;
	}
	for (int i = 0; i < BLOCKSIZE; i++) 
	{
		char temp = m._map[Blockpt[i].getY()][Blockpt[i].getX()];
		GameUtillFunc::gotoxy(MAPINITX+Blockpt[i].getX(), MAPINITY+Blockpt[i].getY());
		if (temp == 3)
		{
			cout << "■";
		}
	}
}

void Block::Move(Map& m,int px, int py)
{
	// 기존의 블럭 삭제
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		GameUtillFunc::gotoxy(MAPINITX+Blockpt[i].getX(), MAPINITY+Blockpt[i].getY());
		char temp = m._map[Blockpt[i].getY()][Blockpt[i].getX()];
		if (temp == 3)
		{
			cout << " ";
			m._map[Blockpt[i].getY()][Blockpt[i].getX()] = 0;
		}
	}
	// 그림자 블럭 삭제
	for (int i = 0; i < BLOCKSIZE; i++)
	{
		GameUtillFunc::gotoxy(MAPINITX+ShadowBlockpt[i].getX(),MAPINITY+ShadowBlockpt[i].getY());
		char shadowTemp = m._map[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()];
		if (shadowTemp == 4)
		{
			cout << " ";
			m._map[ShadowBlockpt[i].getY()][ShadowBlockpt[i].getX()] = 0;
		}
	}
	if (m._map[Blockpt[0].getY()][Blockpt[0].getX() + px] > 0 ||
		m._map[Blockpt[1].getY()][Blockpt[1].getX() + px] > 0 ||
		m._map[Blockpt[2].getY()][Blockpt[2].getX() + px] > 0 ||
		m._map[Blockpt[3].getY()][Blockpt[3].getX() + px] > 0)
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

bool Block::BlockLandingCheck(Map& m, Block b)
{
	if (m._map[b.Blockpt[0].getY() + 1][b.Blockpt[0].getX()] == 1 || m._map[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 1 ||
		m._map[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 1 || m._map[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 1)
	{
		m._map[b.Blockpt[0].getY()][b.Blockpt[0].getX()] = 2;
		m._map[b.Blockpt[1].getY()][b.Blockpt[1].getX()] = 2;
		m._map[b.Blockpt[2].getY()][b.Blockpt[2].getX()] = 2;
		m._map[b.Blockpt[3].getY()][b.Blockpt[3].getX()] = 2;
		return true; // 닿으면 true 반환
	}
	else if (m._map[b.Blockpt[0].getY() + 1][b.Blockpt[0].getX()] == 2 || m._map[b.Blockpt[1].getY() + 1][b.Blockpt[1].getX()] == 2 ||
		m._map[b.Blockpt[2].getY() + 1][b.Blockpt[2].getX()] == 2 || m._map[b.Blockpt[3].getY() + 1][b.Blockpt[3].getX()] == 2)
	{
		m._map[b.Blockpt[0].getY()][b.Blockpt[0].getX()] = 2;
		m._map[b.Blockpt[1].getY()][b.Blockpt[1].getX()] = 2;
		m._map[b.Blockpt[2].getY()][b.Blockpt[2].getX()] = 2;
		m._map[b.Blockpt[3].getY()][b.Blockpt[3].getX()] = 2;
		return true; // 닿으면 true 반환
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

void Block::Rotate(Map&m)
{
	switch (_random)
	{
	case 1: // 네모 블럭
		Move(m);
		break;
	case 2: // 음수 처리까지
		if (_RotateCount % 4 == 0)
		{
			if ((m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() - 1] == 1 || m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() - 2][Blockpt[1].getX()] == 1 || m._map[Blockpt[2].getY() - 2][Blockpt[2].getX()] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[1].getX() - 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() - 2] == 2))
			{
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() - 1);
				Blockpt[1].setY(Blockpt[1].getY() - 1);
				Blockpt[2].setY(Blockpt[2].getY() - 2);
				Blockpt[3].setX(Blockpt[3].getX() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 1)
		{
			if ((m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() + 1] == 1 || m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY()][Blockpt[2].getX() + 2] == 1 || m._map[Blockpt[2].getY()][Blockpt[2].getX() + 2] == 2) ||
				(m._map[Blockpt[3].getY()- 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY()- 2][Blockpt[3].getX()] == 2))
			{
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() + 1);
				Blockpt[1].setY(Blockpt[1].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() + 2);
				Blockpt[3].setY(Blockpt[3].getY() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 2)
		{
			if ((m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() + 1] == 1 || m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() + 2][Blockpt[2].getX()] == 1 || m._map[Blockpt[2].getY() + 2][Blockpt[2].getX()] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[3].getX() + 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() + 2] == 2))
			{
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() + 1);
				Blockpt[1].setY(Blockpt[1].getY() + 1);
				Blockpt[2].setY(Blockpt[2].getY() + 2);
				Blockpt[3].setX(Blockpt[3].getX() + 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 3)
		{
			if ((m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() - 1] == 1 || m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY()][Blockpt[2].getX() - 2] == 1 || m._map[Blockpt[2].getY()][Blockpt[2].getX() - 2] == 2) ||
				(m._map[Blockpt[3].getY()+ 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY()+ 2][Blockpt[3].getX()] == 2))
			{
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() - 1);
				Blockpt[1].setY(Blockpt[1].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() - 2);
				Blockpt[3].setY(Blockpt[3].getY() + 2);
				_RotateCount++;
			}
		}
		break;
	case 3:
		if (_RotateCount % 2 == 0)
		{
			if ((m._map[Blockpt[0].getY() + 3][Blockpt[0].getX() + 3] == 1 || m._map[Blockpt[0].getY() + 3][Blockpt[0].getX() + 3] == 2) ||
				(m._map[Blockpt[1].getY() + 2][Blockpt[1].getX() + 2] == 1 || m._map[Blockpt[1].getY() + 2][Blockpt[1].getX() + 2] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[1].getX() + 1] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 3);
				Blockpt[0].setY(Blockpt[0].getY() + 3);
				Blockpt[1].setX(Blockpt[1].getX() + 2);
				Blockpt[1].setY(Blockpt[1].getY() + 2);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 2 == 1)
		{
			if ((m._map[Blockpt[0].getY() - 3][Blockpt[0].getX() - 3] == 1 || m._map[Blockpt[0].getY() - 3][Blockpt[0].getX() - 3] == 2) ||
				(m._map[Blockpt[1].getY() - 2][Blockpt[1].getX() - 2] == 1 || m._map[Blockpt[1].getY() - 2][Blockpt[1].getX() - 2] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[1].getX() - 1] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 3);
				Blockpt[0].setY(Blockpt[0].getY() - 3);
				Blockpt[1].setX(Blockpt[1].getX() - 2);
				Blockpt[1].setY(Blockpt[1].getY() - 2);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				_RotateCount++;
			}
		}
		break;
	case 4:
		if (_RotateCount % 2 == 0)
		{
			if ((m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 1 || m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 2) ||
				(m._map[Blockpt[1].getY() - 2][Blockpt[1].getX() - 2] == 1 || m._map[Blockpt[1].getY() - 2][Blockpt[1].getX() - 2] == 2) ||
				(m._map[Blockpt[2].getY() - 3][Blockpt[2].getX() - 3] == 1 || m._map[Blockpt[2].getY() - 3][Blockpt[1].getX() - 3] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 1);
				Blockpt[0].setY(Blockpt[0].getY() - 1);
				Blockpt[1].setX(Blockpt[1].getX() - 2);
				Blockpt[1].setY(Blockpt[1].getY() - 2);
				Blockpt[2].setX(Blockpt[2].getX() - 3);
				Blockpt[2].setY(Blockpt[2].getY() - 3);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 2 == 1)
		{
			if ((m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 1 || m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 2) ||
				(m._map[Blockpt[1].getY() + 2][Blockpt[1].getX() + 2] == 1 || m._map[Blockpt[1].getY() + 2][Blockpt[1].getX() + 2] == 2) ||
				(m._map[Blockpt[2].getY() + 3][Blockpt[2].getX() + 3] == 1 || m._map[Blockpt[2].getY() + 3][Blockpt[1].getX() + 3] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 1);
				Blockpt[0].setY(Blockpt[0].getY() + 1);
				Blockpt[1].setX(Blockpt[1].getX() + 2);
				Blockpt[1].setY(Blockpt[1].getY() + 2);
				Blockpt[2].setX(Blockpt[2].getX() + 3);
				Blockpt[2].setY(Blockpt[2].getY() + 3);
				_RotateCount++;
			}
		}
		break;
	case 5:
		if (_RotateCount % 2 == 0)
		{
			if ((m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() - 1] == 1 || m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() - 1);
				Blockpt[1].setY(Blockpt[1].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setY(Blockpt[3].getY() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 2 == 1)
		{
			if ((m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() + 1] == 1 || m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() + 1);
				Blockpt[1].setY(Blockpt[1].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setY(Blockpt[3].getY() + 2);
				_RotateCount++;
			}
		}
		break;
	case 6:
		if (_RotateCount % 2 == 0)
		{
			if ((m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() + 1] == 1 || m._map[Blockpt[1].getY() + 1][Blockpt[1].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() + 1);
				Blockpt[1].setY(Blockpt[1].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setY(Blockpt[3].getY() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 2 == 1)
		{
			if ((m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() - 1] == 1 || m._map[Blockpt[1].getY() - 1][Blockpt[1].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 1 || m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[1].setX(Blockpt[1].getX() - 1);
				Blockpt[1].setY(Blockpt[1].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setY(Blockpt[3].getY() + 2);
				_RotateCount++;
			}
		}
		break;
	case 7:
		if (_RotateCount % 4 == 0)
		{
			if ((m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 1 || m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[1].getX() - 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() - 2] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 1);
				Blockpt[0].setY(Blockpt[0].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setX(Blockpt[3].getX() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 1)
		{
			if ((m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() - 1] == 1 || m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY() - 2][Blockpt[1].getX()] == 1 || m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 1);
				Blockpt[0].setY(Blockpt[0].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setY(Blockpt[3].getY() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 2)
		{
			if ((m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 1 || m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[1].getX() + 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() + 2] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 1);
				Blockpt[0].setY(Blockpt[0].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setX(Blockpt[3].getX() + 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 3)
		{
			if ((m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() + 1] == 1 || m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY() + 2][Blockpt[1].getX()] == 1 || m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 1);
				Blockpt[0].setY(Blockpt[0].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setY(Blockpt[3].getY() + 2);
				_RotateCount++;
			}
		}
		break;
	case 8:
		if (_RotateCount % 4 == 0)
		{
			if ((m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 1 || m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY() - 2][Blockpt[1].getX()] == 1 || m._map[Blockpt[3].getY() - 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 1);
				Blockpt[0].setY(Blockpt[0].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setY(Blockpt[3].getY() - 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 1)
		{
			if ((m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() - 1] == 1 || m._map[Blockpt[0].getY() + 1][Blockpt[0].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() - 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[1].getX() + 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() + 2] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 1);
				Blockpt[0].setY(Blockpt[0].getY() + 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() - 1);
				Blockpt[3].setX(Blockpt[3].getX() + 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 2)
		{
			if ((m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 1 || m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() - 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() + 1] == 2) ||
				(m._map[Blockpt[3].getY() + 2][Blockpt[1].getX()] == 1 || m._map[Blockpt[3].getY() + 2][Blockpt[3].getX()] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() - 1);
				Blockpt[0].setY(Blockpt[0].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() + 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setY(Blockpt[3].getY() + 2);
				_RotateCount++;
			}
		}
		else if (_RotateCount % 4 == 3)
		{
			if ((m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() + 1] == 1 || m._map[Blockpt[0].getY() - 1][Blockpt[0].getX() + 1] == 2) ||
				(m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 1 || m._map[Blockpt[2].getY() + 1][Blockpt[2].getX() - 1] == 2) ||
				(m._map[Blockpt[3].getY()][Blockpt[1].getX() - 2] == 1 || m._map[Blockpt[3].getY()][Blockpt[3].getX() - 2] == 2))
			{
				Move(m);
				break;
			}
			else
			{
				Move(m);
				Blockpt[0].setX(Blockpt[0].getX() + 1);
				Blockpt[0].setY(Blockpt[0].getY() - 1);
				Blockpt[2].setX(Blockpt[2].getX() - 1);
				Blockpt[2].setY(Blockpt[2].getY() + 1);
				Blockpt[3].setX(Blockpt[3].getX() - 2);
				_RotateCount++;
			}
		}
		break;
	default:
		break;
	}
}