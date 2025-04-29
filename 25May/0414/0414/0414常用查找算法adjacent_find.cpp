# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
adjacent_find：查找相邻重复元素，返回相邻元素的第一个位置的迭代器

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
		cout << "未找到相邻重复元素" << endl;
	}
	else
	{
		// 找到第一个符合条件的元素就返回
		cout << "找到相邻重复元素" << *it << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}
