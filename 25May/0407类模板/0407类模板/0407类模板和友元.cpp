# include <iostream>
using namespace std;
#include<string>

/*
��ģ�������Ԫ���������ں�����ʵ��

ȫ�ֺ�������ʵ��--ֱ��������������Ԫ���� ��������ʵ��
ȫ�ֺ�������ʵ��--��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
*/

template<class T1, class T2>
class Person;
// ����ʵ��
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
	cout << "����ʵ��" << endl;
	cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
}

// ͨ��ȫ�ֺ�����ӡ��Ϣ
template<class T1, class T2>
class Person
{
	// ȫ�ֺ��� ����ʵ��
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
	}
	// ȫ�ֺ��� ����ʵ��
	//friend void printPerson2(Person<T1, T2>p); // ��ͨ��������
	friend void printPerson2<>(Person<T1, T2>p); // ����ģ������
	// ���Ǳ��� ��Ҫ�ñ�������ǰ֪��


public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;
};

// ����ʵ��
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>p)
//{
//	cout << "����ʵ��" << endl;
//	cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
//}

void test1()
{
	Person<string, int>p("Tom", 100);
	printPerson(p);
}

void test2()
{
	Person<string, int>p("Alice", 20);
	printPerson2(p);
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
