# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
binary_search:����ָ��Ԫ���Ƿ���ڣ��ҵ�������true������false

bool binary_search(iterator beg, iterator end, value)
�����������в�����

*/


void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool it = binary_search(v.begin(), v.end(), 8);
	// һ������������
	if (it)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

int main()
{
	test1();
	system("pause");

	return 0;
}
