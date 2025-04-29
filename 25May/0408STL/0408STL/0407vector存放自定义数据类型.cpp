# include <iostream>
using namespace std;
#include <vector>
#include <string>
// vector中存放自定义的数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

// 存放自定义数据类型
void test1()
{
	vector<Person> v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	// 向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 遍历迭代器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name = " << (*it).m_Name << " age = " << (*it).m_Age << endl;
		// it解包出来的数据类型是Person

		cout << "name = " << it->m_Name << " age = " << it->m_Age << endl;
		// it为指针
	}
}


// 存放自定义数据类型中的指针
void test2()
{
	vector<Person*> v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	// 向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历迭代器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		// it解包出来的数据类型是Person的指针
		cout << "name = " << (*it)->m_Name << " age = " << (*it)->m_Age << endl;
	}
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
