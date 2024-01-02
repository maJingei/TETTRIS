#pragma once

class Point
{
public:
	Point()
	{
		_x = 0;
		_y = 0;
	}
	Point(int x, int y)
		:_x(x),_y(y)
	{

	}
	Point(Point& p)
	{
		_x = p._x;
		_y = p._y;
	}
	void setPoint(int x, int y) { _x = x; _y = y; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void MoveY(int py) { _y += py; }
	void MoveX(int px) { _x += px; }
	int getX() { return _x; }
	int getY() { return _y; }
protected:
	int _x;
	int _y;
};