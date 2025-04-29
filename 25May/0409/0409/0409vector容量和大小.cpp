# include <iostream>
using namespace std;
#include <vector>
/*
vector�����ʹ�С

������
1 empty(); �ж������Ƿ�Ϊ��
2 capacity(); ����������
3 size(); ����������Ԫ�ظ���
4 resize(int num); �����ƶ������ĳ���Ϊnum �������䳤 ����Ĭ��ֵ�����λ��
��������� ��ĩβ�����������ȵ�Ԫ�ر�ɾ��
5 resize(int num, elem);�����ƶ������ĳ���Ϊnum �������䳤 ����elemֵ�����λ��
��������� ��ĩβ�����������ȵ�Ԫ�ر�ɾ��
*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	// Ϊ��
	if (v1.empty()) {
		cout << "v1Ϊ��" << endl;
	}
	else {
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ:" << v1.size() << endl;
	}

	// ����ָ����С
	v1.resize(15, 100);// �������ذ汾��ָ��Ĭ�����ֵ��
	printVector(v1);// ����ָ���Ĵ�С��ԭ���� Ĭ����0���

	v1.resize(5);
	printVector(v1);// ����ָ���Ĵ�С��ԭ��С ��������ɾ��
}

int main()
{
	test1();
	system("pause");

	return 0;
}
