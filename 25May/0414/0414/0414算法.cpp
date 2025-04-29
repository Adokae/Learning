# include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
/*
�㷨��Ҫ��ͷ�ļ�<algorithm> <functional> <numerical> ���
1<algorithm>������STLͷ�ļ�������һ�� ��Χ�漰���Ƚϡ����������ҡ��������������ơ��޸ĵ�
2<functional> �����С��ֻ��������������������м���ѧ�����ģ�庯��
3<numerical> ����һЩģ���࣬����������������

���ñ����㷨��
1 for_each ��������
for_each(iterator beg, iterator end, _func)
 iterator beg:��ʼ������
 iterator end������������
 _func������������


2 transform ������������һ��������
*/

// �����㷨 for_each
void print1(int val)
{
	cout << val << " ";
}

class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// ��1 ͨ����ͨ���� �ź�����
	for_each(v.begin(), v.end(), print1);
	cout << endl;

	// ��2 ͨ���º��� �ź�������
	for_each(v.begin(), v.end(), print2());
	cout << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
