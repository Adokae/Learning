# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
adjacent_find�����������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����

adjacent_find(iterator beg, iterator end);

*/

void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(10);
	v.push_back(10);
	v.push_back(30);
	v.push_back(30);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "δ�ҵ������ظ�Ԫ��" << endl;
	}
	else
	{
		// �ҵ���һ������������Ԫ�ؾͷ���
		cout << "�ҵ������ظ�Ԫ��" << *it << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}
