# include <iostream>
using namespace std;
#include <string>
/*
类模板实例化出来的对象，向函数传参的方式

总共传参方式有3种：
1 指定传入的类型-- 直接显示对象的数据类型  实际中最常用
2 参数模板化-- 将对象中的参数变为模板进行传递
3 整个类模板 -- 将这个对象类型 模板化进行传递
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

//1 指定传入的类型-- 直接显示对象的数据类型
void printPerson1(Person<string, int> &p)
{
	p.showPerson();
}
void test1()
{
	Person<string, int>p("Tom", 100);
	printPerson1(p);
}

//2 参数模板化-- 将对象中的参数变为模板进行传递
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为" << typeid(T1).name() << endl;// 查看类型
	cout << "T2的类型为" << typeid(T2).name() << endl;
}
void test2()
{
	Person<string, int>p("Alice", 18);
	printPerson2(p);
}

//3 整个类模板 -- 将这个对象类型 模板化进行传递
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	cout << "T的数据类型" << typeid(T).name() << endl;
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
