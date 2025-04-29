# include <iostream>
using namespace std;
#include <string>
//#include "person.h"
// .h中的成员函数编译器无法链接 因为类模板中的成员函数只有在创建的
// 时候才会调用

//该为.cpp文件 第一种解决方式
#include "person.cpp"


// 第二种解决方式
#include "person.hpp"

/*
问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
解决方法：
1 直接包含.cpp源文件
2 将声明和实现写在同一个文件中，并更改后缀名为.hpp hpp为约定的名称
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
	p.showPerson(); // 包含.h的头文件时这两行代码报错 提示：2个无法解析的外部命令
}

int main()
{
	test1();
	system("pause");

	return 0;
}
