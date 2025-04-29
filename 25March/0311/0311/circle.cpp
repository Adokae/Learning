# include "circle.h"

void Circle::setR(int R)
{
	m_R = R;
}
int Circle::getR()
{
	return m_R;
}
void Circle::setC(Point center)
{
	m_Center = center;
}
Point Circle::getC()
{
	return m_Center;
}
