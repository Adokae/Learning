# include <iostream>
using namespace std;
#include <list>
/*
list��С����

������
1 size() ����������Ԫ�ظ���
2 empty() �ж������Ƿ�Ϊ��
3 resize(num) ����ָ����������Ϊnum �������䳤 ����Ĭ��ֵ�����λ��
��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
4 resize(num, elem)����ָ����������Ϊnum �������䳤 ����elem�����λ��
��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

*/
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else {
		cout << "L1��Ϊ��" << endl;
		cout << "L1��Ԫ�ظ�����" << L1.size() << endl;
	}

	// ����ָ����С
	L1.resize(10,1000);
	printList(L1);
	L1.resize(2);
	printList(L1);
}

int main()
{
	test1();
	system("pause");

	return 0;
}
