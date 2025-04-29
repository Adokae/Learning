# include <iostream>
using namespace std;
/*
非静态成员函数只会诞生一份函数实例，多个同类型的对象会共用一块代码
C++中通过this指针区分那个对象调用非静态成员函数

this指针指向被调用的成员函数所属的对象

this指针是隐含每一个非静态成员函数内的一种指针
this指针不需要定义 直接使用即可

this指针的用途：
1 当形参与成员变量同名时，可用this指针来区分
2 在类的非静态成员函数中返回对象本身 可使用return * this

*/

class Person
{
public:

	Person(int age)
	{
		// this指向调用Person成员函数的p1对象
		this->age = age;
	}

	// 返回值是创建一个新的对象
	// 返回引用是返回其本身
	Person& PersonAddAge(Person& p)
	{
		this->age += p.age;
		// this指向p2的指针 而*this指向的p2本身
		return *this;
	}

	int age;
};
//1 解决名称冲突
void test1()
{
	Person p1(18);
	cout << "the age of p1 is " << p1.age << endl;
}

// 2 返回对象本身*this
void test2()
{
	Person p1(10);
	Person p2(10);
	// 函数没有返回值 只能调用1次
	//p2.PersonAddAge(p1);

	// 若函数返回本身
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "the age of p2 is " << p2.age << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
