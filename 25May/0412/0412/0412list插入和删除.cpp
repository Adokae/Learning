# include <iostream>
using namespace std;
#include <list>
/*
list�����ɾ����

������
1 push_back(elem) ������β������һ��Ԫ��
2 pop_back() ɾ�����������һ��Ԫ��
3 push_front(elem) ��������ͷ����һ��Ԫ��
4 pop_front() ��������ͷ�Ƴ���һ��Ԫ��
5 inset(pos,elem) ��posλ�ò�elemԪ�صĿ��� ���������ݵ�λ��
6 insert(pos,n,elem) ��posλ�ò�n��elem���� �޷���ֵ
7 insert(pos,beg,end)  ��posλ�ò�[beg,end)���� �޷���ֵ
8 clear() �Ƴ���������������
9 erase(beg,end) ɾ��[beg,end)��������� ������һ�����ݵ�λ��
10 erase(pos) ɾ��posλ�õ����� ������һ�����ݵ�λ��
11 remove(elem) �Ƴ�������������elemֵƥ���Ԫ��


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

	// β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	L1.push_front(400);
	printList(L1);

	// βɾ
	L1.pop_back();
	printList(L1);

	// ͷɾ
	L1.pop_front();
	printList(L1);

	//����
	//L1.insert(L1.begin(), 1000);

	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	// ɾ��
	it = L1.begin();
	L1.erase(++it);
	printList(L1);

	// �Ƴ�
	L1.push_back(100000);
	printList(L1);
	L1.push_back(100000);
	L1.push_back(100000);
	L1.push_back(100000);
	printList(L1);
	L1.remove(100000);
	printList(L1);

	// ���
	L1.clear();
	printList(L1);
}


int main()
{
	test1();
	system("pause");

	return 0;
}
