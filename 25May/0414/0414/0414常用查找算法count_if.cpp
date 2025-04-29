# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
count_if:������ͳ��Ԫ�س��ִ���

cout_if(iterator beg,iterator end,_Pred);
_Pred:ν��

*/

// ������������
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

	// ͳ�ƴ���20�����ĸ���
	int num = count_if(v.begin(), v.end(), GreaterTwenty());
	cout << "�����д���20��Ԫ�صĸ���Ϊ��" << num << endl;
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
	// ͳ���������20����
	int num = count_if(v.begin(), v.end(), AgeGreaterTwenty());
	cout << "�������20������" << num << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
