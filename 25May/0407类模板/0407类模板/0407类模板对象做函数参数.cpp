# include <iostream>
using namespace std;
#include <string>
/*
��ģ��ʵ���������Ķ����������εķ�ʽ

�ܹ����η�ʽ��3�֣�
1 ָ�����������-- ֱ����ʾ�������������  ʵ�������
2 ����ģ�廯-- �������еĲ�����Ϊģ����д���
3 ������ģ�� -- ������������� ģ�廯���д���
*/

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name = " << this->m_Name << " age = " << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

//1 ָ�����������-- ֱ����ʾ�������������
void printPerson1(Person<string, int> &p)
{
	p.showPerson();
}
void test1()
{
	Person<string, int>p("Tom", 100);
	printPerson1(p);
}

//2 ����ģ�廯-- �������еĲ�����Ϊģ����д���
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ" << typeid(T1).name() << endl;// �鿴����
	cout << "T2������Ϊ" << typeid(T2).name() << endl;
}
void test2()
{
	Person<string, int>p("Alice", 18);
	printPerson2(p);
}

//3 ������ģ�� -- ������������� ģ�廯���д���
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	cout << "T����������" << typeid(T).name() << endl;
}
void test3()
{
	Person<string, int>p("Adok", 30);
	printPerson3(p);
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");

	return 0;
}
