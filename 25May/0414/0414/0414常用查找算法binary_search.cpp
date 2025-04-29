# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
binary_search:查找指定元素是否存在，找到，返回true，否则false

bool binary_search(iterator beg, iterator end, value)
在无序序列中不可用

*/


void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool it = binary_search(v.begin(), v.end(), 8);
	// 一定是有序序列
	if (it)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main()
{
	test1();
	system("pause");

	return 0;
}
