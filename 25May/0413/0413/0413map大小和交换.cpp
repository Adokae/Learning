# include <iostream>
using namespace std;
#include <map>
/*
map容器大小与交换

函数：
1 size() 返回容器中元素个数
2 empty() 判断容器是否为空
3 swap(st) 交换两个集合容器

*/
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key值为：" << (*it).first << " value值为：" << (*it).second << endl;
	}
	cout << endl;
}



void test1()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	if (m1.empty())
	{
		cout << "m1为空" << endl;
	}
	else
	{
		cout << "m1不为空" << endl;
		cout << "m1的大小为：" << m1.size() << endl;
	}
}

//交换
void test2()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "交换前：" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "交换后：" << endl;
	printMap(m1);
	printMap(m2);

}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
