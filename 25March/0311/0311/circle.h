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
	int m_R;// �뾶
	// ����������һ������Ϊ��Ա
	Point m_Center; // Բ��
};
