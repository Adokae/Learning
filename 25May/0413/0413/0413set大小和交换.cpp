# include <iostream>
using namespace std;
#include <set>
/*
set��С�ͽ���

������
1 size()  ����������Ԫ����Ŀ
2 empty() �ж������Ƿ�Ϊ��
3 swap()   ����������������

*/
void printSet(const set<int> & S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



// ��С
void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);

	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
	}
}

// ����
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);

	cout << "����ǰ��" << endl;
	printSet(s1);
	printSet(s2);

	s1.swap(s2);
	cout << "������" << endl;
	printSet(s1);
	printSet(s2);

}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
