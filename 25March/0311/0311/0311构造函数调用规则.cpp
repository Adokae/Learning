# include <iostream>
using namespace std;

/*
Ĭ������£�c++���������ٸ�һ�������3��������
1 Ĭ�Ϲ��캯�����޲� ������Ϊ�գ�
2 Ĭ�������������޲� ������Ϊ�գ�
3 Ĭ�Ͽ������캯�� ������ֵ���п���

���캯�����ù���
1 ���û������вι��캯�� c++�����ṩĬ���޲ι��� �����ṩĬ�Ͽ�������
2 ���û����忽�����캯�� c++�����ṩ�������캯��
*/
class Person
{
public:
	/*Person()
	{
		cout << "PersonĬ�Ϲ��캯������" << endl;
	}*/
	/*Person(int age)
	{
		cout << "PersonĬ���вι��캯������" << endl;
		m_Age = age;
	}*/
	Person(const Person& p)
	{
		cout << "Person�������캯������" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "PersonĬ��������������" << endl;
	}
	int m_Age;
};

//void test1()
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p);
//	cout << "p2������ " << p2.m_Age << endl;
//	// ��δд�������캯�� ������������ֵ����
//}

void test2()
{
	Person p3(28);
	Person p4(p3);
	cout << "p4������ " << p4.m_Age << endl;
	// ��д���вι��� ûдĬ�Ϲ��� ��������
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
