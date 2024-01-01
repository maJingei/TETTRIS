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
	bool BlockLandingCheck(Block b, int random);
	void HardLanding();
	friend void run();
protected:
	Point Blockpt[BLOCKSIZE];
	Point ShadowBlockpt[BLOCKSIZE];
	int random;

	//char _randomBlock[BLOCKSIZE][BLOCKSIZE] = { 0 };

	//char _Block1[BLOCKSIZE][BLOCKSIZE] = {
	//{0,0,0,0},
	//{0,0,0,0},
	//{0,2,2,0},
	//{0,2,2,0},
	//};// �簢�� ��

	//char _Block2[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,0,0,0},
	//	{0,0,0,0},
	//	{0,0,2,0},
	//	{0,2,2,2}
	//};// ��ť ��

	//char _Block3[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,2,0,0},
	//	{0,2,0,0},
	//	{0,2,0,0},
	//	{0,2,0,0}
	//};// 1�� ��

	//char _Block4[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,0,0,0},
	//	{0,0,0,0},
	//	{0,0,0,0},
	//	{2,2,2,2}
	//};//���� ��

	//char _Block5[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,0,0,0},
	//	{0,0,0,0},
	//	{0,0,2,2},
	//	{0,2,2,0}
	//}; // ���� ��

	//char _Block6[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,0,0,0},
	//	{0,2,0,0},
	//	{0,2,0,0},
	//	{0,2,2,0}
	//};//�� L�� ��

	//char _Block7[BLOCKSIZE][BLOCKSIZE] = {
	//	{0,0,0,0},
	//	{0,0,2,0},
	//	{0,0,2,0},
	//	{0,2,2,0}
	//};//�� L�� �ݴ� �� 
};