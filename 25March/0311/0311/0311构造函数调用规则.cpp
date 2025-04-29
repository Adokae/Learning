# include <iostream>
using namespace std;

/*
默认情况下，c++编译器至少给一个类添加3个函数：
1 默认构造函数（无参 函数体为空）
2 默认析构函数（无参 函数体为空）
3 默认拷贝构造函数 对属性值进行拷贝

构造函数调用规则：
1 若用户定义有参构造函数 c++不在提供默认无参构造 但会提供默认拷贝构造
2 若用户定义拷贝构造函数 c++不在提供其它构造函数
*/
class Person
{
public:
	/*Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}*/
	/*Person(int age)
	{
		cout << "Person默认有参构造函数调用" << endl;
		m_Age = age;
	}*/
	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person默认析构函数调用" << endl;
	}
	int m_Age;
};

//void test1()
//{
//	Person p;
//	p.m_Age = 18;
//
//	Person p2(p);
//	cout << "p2的年龄 " << p2.m_Age << endl;
//	// 若未写拷贝构造函数 程序自身会进行值拷贝
//}

void test2()
{
	Person p3(28);
	Person p4(p3);
	cout << "p4的年龄 " << p4.m_Age << endl;
	// 若写了有参构造 没写默认构造 函数报错
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
