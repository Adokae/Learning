# include <iostream>
using namespace std;
#include <set>
/*
set�����ɾ����

������
1 inset(elem); �������в���Ԫ��
2 clear(); �������Ԫ��
3 erase(pos) ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
4 erase(beg,end) ɾ������[beg,end)������Ԫ�� ������һ��Ԫ�صĵ�����
5 erase(elem) ɾ��������ֵΪelem��Ԫ��

*/
void printSet(const set<int>& S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



void test1()
{
	set<int> s1;

	// ����
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);

	// ɾ��
	s1.erase(s1.begin());
	printSet(s1);

	//ɾ�����ذ汾
	s1.erase(20);
	printSet(s1);

	//���
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);

}

int main()
{
	test1();
	system("pause");

	return 0;
}
