# include <iostream>
using namespace std;
#include <list>

/*
list������ת������


������
1 reverse() ;��ת����
2 sort();��������
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
	// ��ת
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	cout << "��תǰ" << endl;
	printList(L1);

	// ��ת
	L1.reverse();
	cout << "��ת��" << endl;
	printList(L1);
}

bool myCompare(int v1, int v2)
{
	// ���� ��һ�������ڵڶ�����
	return v1 > v2;
}


// ����
void test2()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);
	cout << "����ǰ" << endl;
	printList(L1);
	// ���в�֧��������ʵ����������� �������ñ�׼�㷨
	// ��֧��������ʵ����������� �ڲ����ṩһЩ�㷨

	L1.sort();// Ĭ��������� ��С���� ����
	cout << "�����" << endl;
	printList(L1);

	// ��������
	L1.sort(myCompare);
	printList(L1);
	cout << "���������" << endl;
	printList(L1);
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
