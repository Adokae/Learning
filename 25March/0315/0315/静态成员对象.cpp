# include <iostream>
using namespace std;

/*
静态成员就是在成员变量和成员函数前加入关键字static，称为静态成员
静态成员分为：
1 静态成员变量
 所有对象共享同一份数据
 在编译阶段分配内存
 类内声明，类外初始化
2 静态成员函数
  所有对象共享同一个函数
  静态成员函数只能访问静态成员变量
*/
class Person
{
public:
	// 静态成员变量
	static int m_A;// 类内声明

	// 静态成员变量也是具有访问权限的
private:
	static int m_B;
};

int Person::m_A = 100; // 类外初始化
int Person::m_B = 200;

void test1()
{
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl; // 输出200 共享同一份数据
}

void test2()
{
	// 静态成员变量 不属于某个对象 所有对象都共享同一份数据
	// 静态成员变量有两种访问方式
	
	// 1 通过对象进行访问
	Person p;
	cout << p.m_A << endl;

	// 2 通过类名进行访问
	cout << Person::m_A << endl;

	// 该代码错误 私有变量 类外无法访问
	//cout << Person::m_B << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
