# include <iostream>
using namespace std;
#include <string>
/*
pair队组创建：成对的数据，利用队组可以返回两个数据

创建方式：
1 pair<type, type> p (value1, value2);
2 pair<type, type> p = make_pair(value1, value2);

*/


void test1()
{
	// 第一种方式创建
	pair<string, int>p("A", 20);
	cout << "name = " << p.first << " age = " << p.second << endl;

	// 第二种方式创建
	pair<string, int>p2 = make_pair("Bob", 40);
	cout << "name = " << p2.first << " age = " << p2.second << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
