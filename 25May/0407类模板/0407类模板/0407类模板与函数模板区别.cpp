# include <iostream>
using namespace std;
#include <string>
/*
��ģ��ͺ���ģ��������Ҫ�����㣺
1 ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
2 ��ģ����ģ������б��п�����Ĭ�ϲ���
*/
//���Ϳ�����Ĭ�ϲ���
template<class NameType, class AgeType = int>
class Person
{
public:
	
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name = " << m_Name << " age = " << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1 ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test1()
{
	//Person p("Tom", 100); // �޷�ʹ���Զ����ͽ����Ƶ�
	Person<string, int>p("Tom", 100);
	p.showPerson();
}

//2 ��ģ����ģ������б��п�����Ĭ�ϲ���
void test2()
{
	Person<string>p("Tim", 99);// ����ģ���е�����������Ĭ�ϲ���
	p.showPerson();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
