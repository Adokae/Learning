# include <iostream>
using namespace std;
#include <set>

/*
set��multiset������
1 set�����Բ����ظ����� multiset����
2 set�������ݵ�ͬʱ�᷵�ز����� ��ʾ�����Ƿ�ɹ�
3 mutiset���������� ��˿��Բ����ظ�����

*/


void test1()
{
	set<int> s1;
	pair <set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
	s1.insert(20);

	multiset<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(10);
	for (multiset<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


int main()
{
	test1();
	system("pause");

	return 0;
}
