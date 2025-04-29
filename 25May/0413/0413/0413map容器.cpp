# include <iostream>
using namespace std;
#include <map>

/*
map容器基本概念：
1 map中所有元素都是pair
2 pair中第一个元素为key(键值) 起到索引作用 第二个元素为value（实值）
3 所有元素都会根据元素的键值自动排序

本质：
map1/multimap属于关联式容器 底层结构是用二叉树实现

优点：
1 可以根据key值快速找到value值

map与multimap区别：
1 map容器不允许容器中有重复key值元素
2 multimap允许容器中有重复key值元素

map构造和赋值：
构造：
1 map<T1, T2> mp 默认构造函数
2 map(const map &mp); 拷贝构造函数

赋值：
map& operator=(const map &mp) 重载=操作符
*/
void printMap(map<int, int>& mp)
{
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "key值" << (*it).first << " value值" << (*it).second << endl;
	}
	cout << endl;
}


void test1()
{
	map<int, int>m;
	// 默认按key值进行排序
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	// 拷贝构造
	map<int, int>m2(m);
	printMap(m2);

	// 赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}
int main()
{
	test1();
	system("pause");

	return 0;
}
