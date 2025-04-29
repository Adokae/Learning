# include <iostream>
using namespace std;
/*
const修饰成员函数：
常函数：
1 成员函数加const后称之为常函数
2 常函数内不可以修改成员属性
3 成员属性声明时加入关键字mutable后 在常函数中依然可以修改

常对象：
1 声明对象前加const称该兑现为常对象
2 常对象只能调用常函数
*/
class Person
{
public:

	// this指针的本质是指针常量 指针指向不可修改
	// this指针不可以修改指针的指向
	// 加const后实际上是const Person * const this;
	// 成员函数后加const 修饰的是this指针 让指针指向的值也不可以修改
	void showPerson() const
	{
		// 本质上是this->m_A = 10;
		//m_A = 100;
		m_B = 20;
	}
	void func()
	{
		m_A = 100;
	}

	int m_A;
	mutable int m_B;// 特殊变量 使其即使在常函数中 也能修改这个值
};

// 常对象
void test1()
{
	const Person p;// 在对象前加const
	//p.m_A = 100; // 无法修改
	p.m_B = 200; // 加mutable后可以修改

	p.showPerson(); //常对象只能调用常函数
	//p.func();
	// 常对象不能调用普通成员函数 因为普通成员函数可以修改属性
}
int main()
{
	test1();
	system("pause");

	return 0;
}
