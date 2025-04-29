# include <iostream>
using namespace std;

/*
拷贝构造函数调用时机：
1 使用一个已经创建完毕的对象来初始化一个新对象
2 值传递的方式给函数参数传值
3 以值范式返回局部对象
*/
class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}
	Person(const Person & p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	int m_Age;
};

//1 使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2的年龄" << p2.m_Age << endl;
}

//2 值传递的方式给函数参数传值
void doWork(Person p)
{

}
void test2()
{
	Person p; // 默认构造函数
	doWork(p);// 实参传给形参的时候 会调用拷贝构造函数
}

//3 以值方式返回局部对象
Person doWork2()
{
	Person p1;
	return p1;// 返回的是按p1所拷贝的新的对象
}

void test3()
{
	Person p = doWork2();// 接收的p和函数中定义的p1不是同一个对象
}

int main()
{
	//test1();
	test3();
	system("pause");

	return 0;
}
