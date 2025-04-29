# include <iostream>
using namespace std;
/*
�����������࣬��������������������
�ֱ�ʹ��ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
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

	// ���ó�Ա�����ж��������Ƿ����
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

// ����ȫ�ֺ����ж������������Ƿ����
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


	// ȫ�ֺ���
	bool ref = isSame(c1, c2);
	if (ref)
	{
		cout << "c1��c2���" << endl;
	}
	else
	{
		cout << "c1��c2�����" << endl;
	}
	// ��Ա����
	bool ret = c1.isSame2(c2);
	if (ret)
	{
		cout << "��Ա���� c1��c2���" << endl;
	}
	else
	{
		cout << "��Ա���� c1��c2�����" << endl;
	}
	system("pause");

	return 0;
}
