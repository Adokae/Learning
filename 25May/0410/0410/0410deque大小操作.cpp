# include <iostream>
using namespace std;
#include <deque>
/*
deque��С����

������
1 deque.empty();�ж������Ƿ�Ϊ��
2 deque.size();����������Ԫ�ظ���
3 deque.resize(num);����ָ�������ĳ���Ϊnum �������䳤���������ֵ�����λ��
��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

4 deque.resize(num, len);����ָ�������ĳ���Ϊnum �������䳤������elem�����λ��
��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

*/
void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	if (d1.empty()) {
		cout << "d1Ϊ��" << endl;
	}
	else {
		cout << "d1��Ϊ��" << endl;
		cout << "d1��СΪ��" << d1.size() << endl; // û�������ĵĸ���
	}

	// ����ָ����С
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

int main()
{
	test1();
	system("pause");

	return 0;
}
