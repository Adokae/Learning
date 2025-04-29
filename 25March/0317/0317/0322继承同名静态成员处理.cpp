# include <iostream>
using namespace std;
/*
继承中同名的静态成员处理方式

静态成员与非静态成员出现同名，处理方式一致：
1 访问子类同名成员 直接访问即可
2 访问父类同名成员 需要加作用域
*/
class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base下的静态成员函数func()" << endl;
	}

};
int Base::m_A = 100;

class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son下的静态成员函数func()" << endl;
	}
};
int Son::m_A = 200;

// 同名静态成员属性
void test1()
{
	// 1 通过对象访问数据
	cout << "通过对象来访问数据" << endl;
	Son s;
	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;
	// 2 通过类名访问数据
	cout << "通过类名来访问数据" << endl;
	cout << "Son下的m_A = " << Son::m_A << endl;
	cout << "Base下的m_A = " << Base::m_A << endl; // 通过父类
	cout << "Base下的m_A = " << Son::Base::m_A << endl;// 通过子类
	//通过子类访问父类下的数据 第一个双冒号表示子类要通过类名的方式访问数据
	// 第二个双冒号表示父类作用域下的某个数据
}

//静态成员函数
void test2()
{
	// 1 通过对象访问
	cout << "通过对象来访问" << endl;
	Son s;
	s.func();
	s.Base::func();
	// 2 通过类名访问
	// 子类出现与父类同名静态成员函数 隐藏父类中所有同名成员函数
	// 若想访问父类中被隐藏的成员函数 需要加作用域
	cout << "通过类名来访问" << endl;
	Son::func();
	Son::Base::func();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
