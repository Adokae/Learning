# include <iostream>
using namespace std;

/*
多继承：一个类继承多个类
语法：class 子类：继承方式 父类1，继承方式 父类2...
多继承可能引发父类中同名成员出现 需要加作用域区分

实际开发中不建议使用多继承
*/
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test1()
{
	Son s;
	cout << "sizeof the son is " << sizeof(s) << endl;
	//cout << "m_A = " << s.m_A << endl;// 但若是两个父类中都有m_A 报错
	// 父类中出现同名变量 使用作用域
	cout << "m_A = " << s.Base1::m_A << endl;
	cout << "m_A = " << s.Base2::m_A << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
