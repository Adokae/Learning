# include <iostream>
using namespace std;
#include<string>

/*
类模板配合友元函数的类内和类外实现

全局函数类内实现--直接在类内声明友元即可 建议类内实现
全局函数类外实现--需要提前让编译器知道全局函数的存在
*/

template<class T1, class T2>
class Person;
// 类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
	cout << "类外实现" << endl;
	cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
}

// 通过全局函数打印信息
template<class T1, class T2>
class Person
{
	// 全局函数 类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
	}
	// 全局函数 类外实现
	//friend void printPerson2(Person<T1, T2>p); // 普通函数声明
	friend void printPerson2<>(Person<T1, T2>p); // 函数模板声明
	// 还是报错 需要让编译器提前知道


public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;
};

// 类外实现
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>p)
//{
//	cout << "类外实现" << endl;
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
