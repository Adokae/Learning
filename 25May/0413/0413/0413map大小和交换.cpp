# include <iostream>
using namespace std;
#include <map>
/*
map������С�뽻��

������
1 size() ����������Ԫ�ظ���
2 empty() �ж������Ƿ�Ϊ��
3 swap(st) ����������������

*/
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "keyֵΪ��" << (*it).first << " valueֵΪ��" << (*it).second << endl;
	}
	cout << endl;
}



void test1()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	if (m1.empty())
	{
		cout << "m1Ϊ��" << endl;
	}
	else
	{
		cout << "m1��Ϊ��" << endl;
		cout << "m1�Ĵ�СΪ��" << m1.size() << endl;
	}
}

//����
void test2()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "����ǰ��" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "������" << endl;
	printMap(m1);
	printMap(m2);

}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
