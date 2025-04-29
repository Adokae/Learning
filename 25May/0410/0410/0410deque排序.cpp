# include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

/*
deque��������

������
1 sort(iterator beg, iterator end); ��beg��end�����ڵ�Ԫ�ؽ�������
*/
void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void test1() {
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(25);
	d.push_back(15);
	printDeque(d);

	// ���� Ĭ�ϴ�С������������
	// ����֧��������ʵĵ����������� ������ʹ��sort�㷨ֱ�Ӷ���������� ��vector
	sort(d.begin(), d.end());
	cout << "�����:" << endl;
	printDeque(d);
}

int main()
{
	test1();
	system("pause");

	return 0;
}
