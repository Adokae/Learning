# include <iostream>
using namespace std;
#include <list>
/*
list数据存取：

函数：
1 front();返回第一个元素
2 back(); 返回最后一个元素
*/

void test1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	// 不可以用[]方式访问数据 
	// 无法用at方式访问
	//原因在于list本质上是链表 不是用连续线性空间存储数据 迭代器不支持随机访问

	cout << "首位元素：" << L1.front() << endl;
	cout << "尾部元素:" << L1.back() << endl;

	// 迭代器不支持随机访问
	list<int>::iterator it = L1.begin();
	it++;// 只能一个个迭代 双向递增
	cout << *(it++) << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}
