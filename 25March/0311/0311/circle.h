# pragma once
# include <iostream>
using namespace std;
# include "point.h"

class Circle
{
public:
	void setR(int R);
	int getR();
	void setC(Point center);
	Point getC();

private:
	int m_R;// 半径
	// 在类中让另一个类作为成员
	Point m_Center; // 圆心
};
