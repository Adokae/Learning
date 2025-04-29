#pragma once
# include <iostream>
using namespace std;

class Point
{
public:
	void setX(int X);
	int getX();
	void setY(int Y);
	int getY();

private:
	int m_X;
	int m_Y;
};