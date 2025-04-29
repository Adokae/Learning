# include <iostream>
using namespace std;
/*
类模板中成员函数和普通类中成员函数创建实际是有去别的：
1 普通类中成员函数一开始就可以创建
2 类模板中成员函数在调用时才创建
*/
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;// T可能是任何类型
	// 类模板中的成员函数 一开始不会创建
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test1()
{
	MyClass<Person1>m;
	m.func1();// 只有在调用时才能确定数据类型 才能去创建
	//m.func2();
}

int main()
{
	test1();
	system("pause");

	return 0;
}
