# include <iostream>
using namespace std;
#include <vector>
/*
��vector���ݽ��д�ȡ����

������
1 at(int idx); // ��������idx��ָ������
2 operator[];��������idx��ָ������
3 front();���������еĵ�һ������Ԫ��
4 back();�������������һ������Ԫ��
*/


void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	// ͨ��[]��ʽ����
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	// ͨ��at��ʽ����
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// ������Ԫ��
	cout << "��һ��Ԫ��Ϊ��" << v1.front() << endl;
	// �������һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ��" << v1.back() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
