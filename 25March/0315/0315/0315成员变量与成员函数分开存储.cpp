# include <iostream>
using namespace std;

/*
类内的成员变量与成员函数分开存储
只有非静态成员变量才属于类的对象上
*/

class Person
{
	int m_A;// 非静态成员变量 属于类的对象上

	static int m_B;// 静态成员变量 不属于类对象上

	void func() {} // 非静态成员函数 不属于类对象上

	static void func() {} // 静态成员函数 不属于类对象上
};
int Person::m_B = 0;

void test1()
{
	Person p;
	// 空对象占用内存空间为：1个字节
	// 编译器给每个空对象分配一个字节空间 为了区分对象占内存的位置
	// 每个空对象也应该具有独一无二的内存地址
	cout << "size of p is " << sizeof(p) << endl;
}

void test2()
{
	Person p;
	cout << "size of p is " << sizeof(p) << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
