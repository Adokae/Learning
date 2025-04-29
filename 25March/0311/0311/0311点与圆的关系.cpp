# include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

/*
����һ��Բ�࣬����һ�����࣬�������Բ�Ĺ�ϵ
����Բ�� Բ�� Բ��
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
//	int m_R;// �뾶
//// ����������һ������Ϊ��Ա
//	Point m_Center; // Բ��
//};

// ȫ�ֺ��� �жϵ���Բ�Ĺ�ϵ
void relation(Circle& c, Point& p)
{
	// �����������ƽ��
	int distance = 
		(c.getC().getX() - p.getX())*(c.getC().getX() - p.getX())+  
		(c.getC().getY() - p.getY())* (c.getC().getY() - p.getY());
	int r_distance = c.getR()*c.getR();
	if (distance == r_distance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > r_distance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}
int main()
{
	// ����Բ��Բ��
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setC(center);

	// ���õ�
	Point p;
	p.setX(10);
	p.setY(14);

	// �жϹ�ϵ
	relation(c,p);

	system("pause");

	return 0;
}
