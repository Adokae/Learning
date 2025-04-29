# include <iostream>
using namespace std;
#include <map>

/*
map查找和统计

1 find(key) 检查key是否存在，存在，返回该键的元素的迭代器，若不存在，返回set.end()
2 count(key) 统计key的元素个数
*/
void test1()
{
	// 查找
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
//m.insert(make_pair(3, 40)); // 无法插入

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "查找到元素key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}


	// 统计 map不允许插入重复key元素 num要么为0 要么为1
	int num = m.count(3);
	cout << "num = " << num << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
