# include <iostream>
using namespace std;
# include <string>
/*
C++���еĳ�Ա��������һ����Ķ��� �Ƹó�ԱΪ�����Ա
�������������Ϊ�����Ա�������ʱ���ȹ���������ڹ�������
������˳���빹���෴

*/
// ���磺
// B�����ж���A��Ϊ��Ա AΪ�����Ա
class A{};
class B
{
	A a;
};

class Phone
{
public:
	Phone(string pName)
	{
		cout << "Phone�Ĺ��캯��" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "Phone����������" << endl;
	}
	string m_PName;
};

class Person
{
public:

	// Phone m_Phone = pName;
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person�Ĺ��캯��" << endl;
	}
	~Person()
	{
		cout << "Person����������" << endl;
	}
	string m_Name;
	Phone m_Phone;
};

void test1()
{
	Person p("����", "ƻ��");
	cout << p.m_Name << "����"  << p.m_Phone.m_PName << "�ֻ�" << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
