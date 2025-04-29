# include <iostream>
using namespace std;
/*
设置立方体类，求出立方体的面积和体积，
分别使用全局函数和成员函数判断两个立方体是否相等
*/

class Cube
{
public:
	void setm_L(double L)
	{
		m_L = L;
	}
	double getm_L()
	{
		return m_L;
	}
	void setm_H(double H)
	{
		m_H = H;
	}
	double getm_H()
	{
		return m_H;
	}
	void setm_W(double W)
	{
		m_W = W;
	}
	double getm_W()
	{
		return m_W;
	}
	double getArea()
	{
		return 2 * (m_L * m_H + m_L * m_W + m_H * m_W);
	}
	double getVolume()
	{
		return m_L * m_H * m_W;
	}

	// 利用成员函数判断两个类是否相等
	bool isSame2(Cube & c)
	{
		if (m_L == c.getm_L() && m_H == c.getm_H() && m_W == c.getm_W())
		{
			return true;
		}
		return false;
	}
private:
	double m_L;
	double m_H;
	double m_W;
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getm_L() == c2.getm_L() && c1.getm_H() == c2.getm_H() && c1.getm_W() == c2.getm_W())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setm_H(10);
	c1.setm_L(10);
	c1.setm_W(10);
	cout << "the area of c1 " << c1.getArea() << endl;
	cout << "the volume of c1 " << c1.getVolume() << endl;

	Cube c2;
	c2.setm_H(10);
	c2.setm_L(10);
	c2.setm_W(11);


	// 全局函数
	bool ref = isSame(c1, c2);
	if (ref)
	{
		cout << "c1与c2相等" << endl;
	}
	else
	{
		cout << "c1与c2不相等" << endl;
	}
	// 成员函数
	bool ret = c1.isSame2(c2);
	if (ret)
	{
		cout << "成员函数 c1与c2相等" << endl;
	}
	else
	{
		cout << "成员函数 c1与c2不相等" << endl;
	}
	system("pause");

	return 0;
}
