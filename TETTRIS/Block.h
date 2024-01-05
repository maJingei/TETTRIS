#pragma once
#include"Point.h"
#include"map.h"
#define BLOCKSIZE 4
#define EARX 10
#define EARY 3

class Block
{
public:
	Block();
	void BlockDraw(Map& m);
	void Move(Map& m,int px=0,int py=0);
	bool BlockLandingCheck(Map& m,Block b);
	void HardLanding();
	void Rotate(Map& m);
protected:
	Point Blockpt[BLOCKSIZE];
	Point ShadowBlockpt[BLOCKSIZE];
	int _random;
	int _RotateCount = 0;
};