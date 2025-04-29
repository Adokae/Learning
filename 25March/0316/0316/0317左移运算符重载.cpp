# include <iostream>
using namespace std;

/*
左移运算符重载：
作用：可以输出自定义数据类型
*/

class Person
{
	friend ostream& operator<< (ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	// 不会利用成员函数重载<<运算符 无法实现cout在左侧
	// 成员函数呈现的结果为p<< cout
	/*void operator<<(cout)
	{
	}*/
	int m_A;
	int m_B;
};

// 全局函数重载左移运算符
// 本质上是operator << (cout, p) 简化cout<<p
ostream & operator<< (ostream &cout,Person &p)
{
	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
	return cout;
}
void test1()
{
	Person p(10, 10);
	//p.m_A = 10;
	//p.m_B = 10;
	/*cout << p.m_A << endl;
	cout << p.m_B << endl;*/
	//cout << p;// 全局函数重载无返回值
	cout << p << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
