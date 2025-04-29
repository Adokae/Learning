# include <iostream>
using namespace std;
#include<set>
/*
set/multiset����

�������
1 ����Ԫ�ض����ڲ���ʱ�Զ�����
���ʣ�set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

set��multiset����
1 set���������������ظ���Ԫ��
2 multiset�������������ظ���Ԫ��


set�����븳ֵ��
���죺
1 set<T> st;Ĭ�Ϲ��캯��
2 set(const set &st);�������캯��

��ֵ��
set& operator=(const set &st)���صȺŲ�����
*/

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	set<int>s1;

	// �������� ֻ��insert��ʽ
	// set��������ʱ�Զ�����
	// set��������������ظ�ֵ
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	
	s1.insert(40);
	s1.insert(30);

	printSet(s1);

	// ��������
	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s1;
	printSet(s3);

}

int main()
{
	test1();
	system("pause");

	return 0;
}
