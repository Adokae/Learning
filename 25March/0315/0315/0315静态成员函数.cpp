# include <iostream>
using namespace std;


class Person
{
public:
	// ��̬��Ա����
	static void func()
	{
		m_A = 100;// ��̬��Ա�������ʾ�̬��Ա���� 
		//�����Է��ʷǾ�̬��Ա���� �޷��������Ǹ������µ�m_B
		//m_B = 100;
		cout << "���þ�̬��Ա����func" << endl;
		cout << "m_A= " << m_A << endl;
	}
	static int m_A;
	int m_B;// ���б���

	// ��̬��Ա����Ҳ�Ǿ��з���Ȩ�޵�
private:
	static void func2()
	{
		cout << "���þ�̬func2()����" << endl;
	}
};

int Person::m_A = 0;
void test1()
{
	// 1 ͨ��������з���
	Person p;
	p.func();

	// 2 ͨ���������з���
	Person::func();

	//ֻ�������ڷ���
	//Person::func2();
}

int main()
{
	test1();
	system("pause");

	return 0;
}
