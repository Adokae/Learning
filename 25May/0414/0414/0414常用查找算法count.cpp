# include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
/*
count:ͳ��Ԫ�ظ���

count(iterator beg, iterator end, value)

*/
// ͳ��������������
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(10);
	int num = count(v.begin(), v.end(), 10);
	cout << "10��Ԫ�ظ���Ϊ��" << num << endl;
}

// ͳ���Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};
void test2()
{
	vector<Person>v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 10);
	Person p4("d", 10);
	Person p5("e", 70);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p6("g", 10);
	int num = count(v.begin(), v.end(), p6);

	cout << "��p6������ͬ�������У�" << num << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
