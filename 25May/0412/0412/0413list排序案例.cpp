# include <iostream>
using namespace std;
#include <list>

/*
将Person自定义数据类型进行排序，Person中的属性有姓名、年龄、身高

排序规则：按照年龄进行升序排列 若年龄相同则按照身高进行降序
*/
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;

};

bool comparePerson(Person &p1, Person &p2)
{
	// 按照年龄升序
	if (p1.m_Age == p2.m_Age)
	{
		// 年龄相同 按照身高降序
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
	
}


void test1()
{
	list<Person>L;
	// 准备数据
	Person p1("a", 35, 175);
	Person p2("b", 45, 180);
	Person p3("c", 40, 170);
	Person p4("d", 25, 190);
	Person p5("e", 35, 160);
	Person p6("f", 35, 200);

	// 插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "排序前：" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name = " << (*it).m_Name << " age = " << (*it).m_Age <<  " Height = " << (*it).m_Height << endl;
	}

	// 排序
	cout << "排序后：" << endl;
	L.sort(comparePerson);// 要写回调函数或仿函数
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name = " << (*it).m_Name << " age = " << (*it).m_Age << " Height = " << (*it).m_Height << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}
