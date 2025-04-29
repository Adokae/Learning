# include <iostream>
using namespace std;
#include <list>

/*
list容器反转和排序


函数：
1 reverse() ;反转链表
2 sort();链表排序
*/
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test1()
{
	// 反转
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	cout << "反转前" << endl;
	printList(L1);

	// 反转
	L1.reverse();
	cout << "反转后" << endl;
	printList(L1);
}

bool myCompare(int v1, int v2)
{
	// 降序 第一个数大于第二个数
	return v1 > v2;
}


// 排序
void test2()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);
	cout << "排序前" << endl;
	printList(L1);
	// 所有不支持随机访问迭代器的容器 不可以用标准算法
	// 不支持随机访问迭代器的容器 内部会提供一些算法

	L1.sort();// 默认排序规则 从小到大 升序
	cout << "排序后" << endl;
	printList(L1);

	// 降序排列
	L1.sort(myCompare);
	printList(L1);
	cout << "降序排序后" << endl;
	printList(L1);
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
