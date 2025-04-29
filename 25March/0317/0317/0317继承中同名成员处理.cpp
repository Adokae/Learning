# include <iostream>
using namespace std;

/*
当父类与子类出现同名的成员，如何通过子类对象，访问父类或子类中同名的数据
1 访问子类同名成员 直接访问即可
2 访问父类同名成员 需要加作用域
*/
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base 下的func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base 下的func(int a)调用" << endl;
	}
	int m_A;
};

class Son:public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son 下的func()调用" << endl;
	}
	int m_A;
};
// 同名属性的处理方式
void test1()
{
	Son s;
	// 直接访问是访问子类的
	cout << "Son下的 m_A = " << s.m_A << endl;
	// 通过子类对象访问父类中的同名对象 需要加作用域
	cout << "Base下的 m_A = " << s.Base::m_A << endl;
}

// 同名函数的处理方式
void test2()
{
	Son s;
	s.func();
	s.Base::func();
// 若子类中出现与父类同名的成员函数 
// 子类中的同名成员会隐藏掉父类中所有同名成员函数
	//s.func(100);

// 想访问父类中被隐藏的同名成员函数 需要加作用域
	s.Base::func(100);
}
int main()
{
	test1();
	//test2();
	system("pause");

	return 0;
}
