# include <iostream>
using namespace std;

/*
��̳У�һ����̳ж����
�﷨��class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2...
��̳п�������������ͬ����Ա���� ��Ҫ������������

ʵ�ʿ����в�����ʹ�ö�̳�
*/
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test1()
{
	Son s;
	cout << "sizeof the son is " << sizeof(s) << endl;
	//cout << "m_A = " << s.m_A << endl;// ���������������ж���m_A ����
	// �����г���ͬ������ ʹ��������
	cout << "m_A = " << s.Base1::m_A << endl;
	cout << "m_A = " << s.Base2::m_A << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
