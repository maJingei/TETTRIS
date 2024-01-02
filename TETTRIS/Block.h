#pragma once
#include"Point.h"
#define BLOCKSIZE 4
#define EARX 10
#define EARY 0

class Block
{
public:
	Block();
	void BlockDraw();
	void Move(int px=0,int py=0);
	bool BlockLandingCheck(Block b);
	void HardLanding();
	void Rotate();
	friend void run();
protected:
	Point Blockpt[BLOCKSIZE];
	Point ShadowBlockpt[BLOCKSIZE];
	int random;
	int RotateCount = 0;
};