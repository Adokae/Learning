# include <iostream>
using namespace std;
#include <vector>
/*
vectorԤ���ռ䣺
����vector�ڶ�̬��չ����ʱ����չ����

������
1 reserve(int len); ����Ԥ��len��Ԫ�س��� Ԥ��λ�ò���ʼ�� Ԫ�ز��ɷ���
*/

void test1() {
	vector<int>v;
	//����reserveԤ���ռ�
	v.reserve(100000);

	int num = 0; // ͳ�ƿ��ٴ���
	int* p= NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;// ���ܻ᲻�Ϸ����µ��ڴ�ռ�
		}
	}

	cout << "num = " << num << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
