# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
count_if:按条件统计元素出现次数

cout_if(iterator beg,iterator end,_Pred);
_Pred:谓词

*/

// 内置数据类型
class GreaterTwenty
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(0);
	v.push_back(6);
	v.push_back(20);
	v.push_back(30);

	// 统计大于20的数的个数
	int num = count_if(v.begin(), v.end(), GreaterTwenty());
	cout << "容器中大于20的元素的个数为：" << num << endl;
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

class AgeGreaterTwenty
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_Age > 20)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void test2()
{
	vector<Person> v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 10);
	Person p4("d", 30);
	Person p5("e", 50);
	Person p6("f", 10);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	// 统计年龄大于20的人
	int num = count_if(v.begin(), v.end(), AgeGreaterTwenty());
	cout << "年龄大于20的人有" << num << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
