# include <iostream>
using namespace std;
/*
�̳���ͬ���ľ�̬��Ա����ʽ

��̬��Ա��Ǿ�̬��Ա����ͬ��������ʽһ�£�
1 ��������ͬ����Ա ֱ�ӷ��ʼ���
2 ���ʸ���ͬ����Ա ��Ҫ��������
*/
class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base�µľ�̬��Ա����func()" << endl;
	}

};
int Base::m_A = 100;

class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son�µľ�̬��Ա����func()" << endl;
	}
};
int Son::m_A = 200;

// ͬ����̬��Ա����
void test1()
{
	// 1 ͨ�������������
	cout << "ͨ����������������" << endl;
	Son s;
	cout << "Son�µ�m_A = " << s.m_A << endl;
	cout << "Base�µ�m_A = " << s.Base::m_A << endl;
	// 2 ͨ��������������
	cout << "ͨ����������������" << endl;
	cout << "Son�µ�m_A = " << Son::m_A << endl;
	cout << "Base�µ�m_A = " << Base::m_A << endl; // ͨ������
	cout << "Base�µ�m_A = " << Son::Base::m_A << endl;// ͨ������
	//ͨ��������ʸ����µ����� ��һ��˫ð�ű�ʾ����Ҫͨ�������ķ�ʽ��������
	// �ڶ���˫ð�ű�ʾ�����������µ�ĳ������
}

//��̬��Ա����
void test2()
{
	// 1 ͨ���������
	cout << "ͨ������������" << endl;
	Son s;
	s.func();
	s.Base::func();
	// 2 ͨ����������
	// ��������븸��ͬ����̬��Ա���� ���ظ���������ͬ����Ա����
	// ������ʸ����б����صĳ�Ա���� ��Ҫ��������
	cout << "ͨ������������" << endl;
	Son::func();
	Son::Base::func();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
