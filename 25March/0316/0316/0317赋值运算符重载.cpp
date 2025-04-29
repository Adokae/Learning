# include <iostream>
using namespace std;

/*
C++编译器给一个类添加四个函数：
1 默认构造函数
2 默认析构函数
3 默认拷贝构造函数
4 赋值运算符operator=，对属性进行值拷贝
*/
// 赋值运算符重载
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	// 浅拷贝 代码崩溃 因为p2释放内存 把原来的p1内存地址也给释放了
	// 使用深拷贝解决
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	// 重载赋值运算符
	Person& operator=(Person &p)
	{
		// 编译器提供浅拷贝
		//m_Age = p.m_Age;
		// 应该先判断是否有属性在堆区 若有先释放干净 然后在深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		// 深拷贝
		m_Age = new int(*p.m_Age);

		return *this;
	}
	int *m_Age;
};
void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;
	cout << "p1的年龄为" << *p1.m_Age << endl;
	cout << "p2的年龄为" << *p2.m_Age << endl;
	cout << "p3的年龄为" << *p3.m_Age << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
