# include <iostream>
using namespace std;

/*
���������������ͬ���ĳ�Ա�����ͨ��������󣬷��ʸ����������ͬ��������
1 ��������ͬ����Ա ֱ�ӷ��ʼ���
2 ���ʸ���ͬ����Ա ��Ҫ��������
*/
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base �µ�func()����" << endl;
	}
	void func(int a)
	{
		cout << "Base �µ�func(int a)����" << endl;
	}
	int m_A;
};

class Son:public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son �µ�func()����" << endl;
	}
	int m_A;
};
// ͬ�����ԵĴ���ʽ
void test1()
{
	Son s;
	// ֱ�ӷ����Ƿ��������
	cout << "Son�µ� m_A = " << s.m_A << endl;
	// ͨ�����������ʸ����е�ͬ������ ��Ҫ��������
	cout << "Base�µ� m_A = " << s.Base::m_A << endl;
}

// ͬ�������Ĵ���ʽ
void test2()
{
	Son s;
	s.func();
	s.Base::func();
// �������г����븸��ͬ���ĳ�Ա���� 
// �����е�ͬ����Ա�����ص�����������ͬ����Ա����
	//s.func(100);

// ����ʸ����б����ص�ͬ����Ա���� ��Ҫ��������
	s.Base::func(100);
}
int main()
{
	test1();
	//test2();
	system("pause");

	return 0;
}
