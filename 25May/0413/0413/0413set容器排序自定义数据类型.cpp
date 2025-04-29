# include <iostream>
using namespace std;
#include <set>

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

class comparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		// �����併��
		return p1.m_Age > p2.m_Age;
	}

};

void test1()
{
	// �Զ����������� ָ���������
	set<Person, comparePerson> s;
	Person p1("a", 20);
	Person p2("b", 50);
	Person p3("c", 30);
	Person p4("d", 10);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name = " << (*it).m_Name << " age = " << (*it).m_Age << endl;
	}
}


int main()
{
	test1();
	system("pause");

	return 0;
}
