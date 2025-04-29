# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
查找算法find_if:按条件查找元素

find_if(iterator beg, iterator end, _Pred)
查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器
 _Pred函数或谓词

*/
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// 查找内置数据类型
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}

// 自定义数据类型
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

class GreaterTwenty
{
public:
	bool operator()(Person& p)
	{
		return p.m_Age > 20;
	}
};
void test2()
{
	vector<Person>v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 找一个年龄大于20的人
	vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterTwenty());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了 name = " << it->m_Name << " age = " << it->m_Age << endl;
	}
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
