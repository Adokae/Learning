# include <iostream>
using namespace std;
#include<vector>
/*
vector�����������
���ܣ�vector����������ǳ����ƣ�Ҳ��Ϊ��������
����ͨ���������
	�����Ǿ�̬�ռ䣬vectro���Զ�̬��չ

��̬��չ��������ԭ�ռ�֮������¿ռ䣬����Ѱ�Ҹ�����ڴ�ռ䣬��ԭ���ݿ������¿ռ䣬�ͷ�ԭ�ռ�

vector�����ĵ�������֧��������ʵĵ�����

vector���캯����
����vector����
������
1 vector<T> v; // ����ģ��ʵ����ʵ�� Ĭ�Ϲ��캯��
2 vector<v.begin(), v.end()> ;// ��v[begin(), end())(ǰ�պ�)�����е�Ԫ�ؿ���������
3 vector(n, elem); // ���캯����n��elem����������
4 vector(const vector &vec)�� // �������캯��

*/
void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " " ;
	}
	cout << endl;
}

void test1() {
	// Ĭ�Ϲ��� �޲ι���
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// ͨ�����䷽ʽ���й���
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	// n��elem�ķ�ʽ���й���
	vector<int>v3(10, 100);
	printVector(v3);

	// ��������
	vector<int>v4(v3);
	printVector(v4);
}

int main()
{
	test1();
	system("pause");

	return 0;
}
