# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
���ò����㷨��飺
1 find ����Ԫ��
2 find_if ����������Ԫ��
3 adjacent_find ���������ظ�Ԫ��
4 bingary_search ���ֲ��ҷ�
5 count ͳ��Ԫ�ظ���
6 count_if ������ͳ��Ԫ�ظ���

find������ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������
������find(iterator beg, iterator end, value);
beg: ��ʼ������
end ����������
value ���ҵ�Ԫ��

*/


// ����������������
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// ����
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}

}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	// ����== �õײ�find֪����ζԱ�
	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
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
// �����Զ�����������
void test2()
{
	vector<Person> v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// �ŵ�������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("b", 20);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);

	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ� name = "<< it->m_Name << " age = " << it->m_Age << endl;
	}
}


int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
