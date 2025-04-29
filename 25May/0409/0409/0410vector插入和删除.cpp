# include <iostream>
using namespace std;
#include <vector>
/*
vector�����ɾ��

������
1 push_back(ele); β������Ԫ��ele
2 pop_back();ɾ�����һ��Ԫ��
3 insert(const_iterator, pos, ele);������ָ��λ��pos����Ԫ��ele
4 insert(const_iterator pos, int count , ele);������ָ��λ��pos����count��Ԫ��ele
5 erase(const_iterator pos);ɾ��������ָ���Ԫ��
6 erase(const_iterator start, const_iterator end);ɾ����������start��end֮���Ԫ��
7 clear()����������е�����Ԫ��
*/
void printVector(vector<int> & v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	vector<int>v1;
	// β�巨��ֵ
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	// β��ɾ��
	v1.pop_back();
	printVector(v1);

	// ���� ��һ�������ǵ�����
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 100);
	printVector(v1);

	// ɾ��
	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(), v1.end());// ����ʼ������ȫ�����
	v1.clear();
	printVector(v1);
}
int main()
{
	test1();
	system("pause");

	return 0;
}
