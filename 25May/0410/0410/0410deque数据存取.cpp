# include <iostream>
using namespace std;
#include <deque>
/*
deque���ݴ�ȡ

������
1 at(int idx);��������idx��ָ�������
2 operator[];����idx��ָ�������
3 front();���������еĵ�һ������Ԫ��
4 back();�������������һ������Ԫ��

*/

void test1() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	// ͨ��[]��ʽ����Ԫ��
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout << endl;

	// ͨ��at��ʽ����
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << " ";
	}
	cout << endl;

	// ������βԪ��
	cout << "��Ԫ��Ϊ��" << d1.front() << endl;
	cout << "βԪ��Ϊ:" << d1.back() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
