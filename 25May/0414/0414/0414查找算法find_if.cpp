# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
�����㷨find_if:����������Ԫ��

find_if(iterator beg, iterator end, _Pred)
����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������
 _Pred������ν��

*/
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// ����������������
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
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}
}

// �Զ�����������
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

	// ��һ���������20����
	vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterTwenty());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��� name = " << it->m_Name << " age = " << it->m_Age << endl;
	}
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
