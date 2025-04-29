# include <iostream>
using namespace std;
#include <string>
/*
类模板作用：
建立一个通用类，类中的成员 数据类型不具体指定，用虚拟的类型来表示

语法：
tempalte<calss T>
类
*/

// 类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name is " << this->m_Name << endl;
		cout << "age is " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test1()
{
	Person<string, int>p1("Tom", 100);
	p1.showPerson();
}
int main()
{
	test1();
	system("pause");

	return 0;
}
