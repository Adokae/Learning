# include <iostream>
using namespace std;
#include <string>
/*
类模板和函数模板区别主要有两点：
1 类模板没有自动类型推导的使用方式
2 类模板在模板参数列表中可以有默认参数
*/
//类型可以有默认参数
template<class NameType, class AgeType = int>
class Person
{
public:
	
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name = " << m_Name << " age = " << m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1 类模板没有自动类型推导的使用方式
void test1()
{
	//Person p("Tom", 100); // 无法使用自动类型进行推导
	Person<string, int>p("Tom", 100);
	p.showPerson();
}

//2 类模板在模板参数列表中可以有默认参数
void test2()
{
	Person<string>p("Tim", 99);// 将类模板中的年龄设置有默认参数
	p.showPerson();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
