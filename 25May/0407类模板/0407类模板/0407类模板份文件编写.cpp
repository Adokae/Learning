# include <iostream>
using namespace std;
#include <string>
//#include "person.h"
// .h�еĳ�Ա�����������޷����� ��Ϊ��ģ���еĳ�Ա����ֻ���ڴ�����
// ʱ��Ż����

//��Ϊ.cpp�ļ� ��һ�ֽ����ʽ
#include "person.cpp"


// �ڶ��ֽ����ʽ
#include "person.hpp"

/*
���⣺��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
���������
1 ֱ�Ӱ���.cppԴ�ļ�
2 ��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp hppΪԼ��������
*/
//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "name = " << this->m_Name << " age = " << this->m_Age << endl;
//}


void test1()
{
	Person<string, int>p("Tom", 99);
	p.showPerson(); // ����.h��ͷ�ļ�ʱ�����д��뱨�� ��ʾ��2���޷��������ⲿ����
}

int main()
{
	test1();
	system("pause");

	return 0;
}
