# include <iostream>
using namespace std;
/*
���ع�ϵ��������������Զ������Ͷ�����жԱȲ���
*/
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	// ����==
	bool operator==(Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		return true;
	}


	string m_Name;
	int m_Age;
};

void test1()
{
	Person p1("Jack", 10);
	Person p2("Tom", 18);
	if (p1 == p2)
	{
		cout << "p1 is same with p2" << endl;
	}
	else
	{
		cout << "p1 is not same with p2" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1 is not same with p2" << endl;
	}
	else
	{
		cout << "p1 is same with p2" << endl;
	}

}
int main()
{
	test1();
	system("pause");

	return 0;
}
