# include <iostream>
using namespace std;


class Person
{
public:
	// 静态成员函数
	static void func()
	{
		m_A = 100;// 静态成员函数访问静态成员变量 
		//不可以访问非静态成员变量 无法区分是那个对象下的m_B
		//m_B = 100;
		cout << "调用静态成员函数func" << endl;
		cout << "m_A= " << m_A << endl;
	}
	static int m_A;
	int m_B;// 共有变量

	// 静态成员函数也是具有访问权限的
private:
	static void func2()
	{
		cout << "调用静态func2()函数" << endl;
	}
};

int Person::m_A = 0;
void test1()
{
	// 1 通过对象进行访问
	Person p;
	p.func();

	// 2 通过类名进行访问
	Person::func();

	//只能在类内访问
	//Person::func2();
}

int main()
{
	test1();
	system("pause");

	return 0;
}
