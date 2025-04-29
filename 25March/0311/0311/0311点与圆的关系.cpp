# include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

/*
设置一个圆类，设置一个点类，计算点与圆的关系
点在圆内 圆外 圆上
*/

//class Point
//{
//public:
//	void setX(int X)
//	{
//		m_X = X;
//	}
//	int getX()
//	{
//		return m_X;
//	}
//	void setY(int Y)
//	{
//		m_Y = Y;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};
//
//class Circle
//{
//public:
//	void setR(int R)
//	{
//		m_R = R;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	void setC(Point center)
//	{
//		m_Center = center;
//	}
//	Point getC()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R;// 半径
//// 在类中让另一个类作为成员
//	Point m_Center; // 圆心
//};

// 全局函数 判断点与圆的关系
void relation(Circle& c, Point& p)
{
	// 计算两点距离平方
	int distance = 
		(c.getC().getX() - p.getX())*(c.getC().getX() - p.getX())+  
		(c.getC().getY() - p.getY())* (c.getC().getY() - p.getY());
	int r_distance = c.getR()*c.getR();
	if (distance == r_distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > r_distance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
int main()
{
	// 设置圆与圆心
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setC(center);

	// 设置点
	Point p;
	p.setX(10);
	p.setY(14);

	// 判断关系
	relation(c,p);

	system("pause");

	return 0;
}
