# include <iostream>
using namespace std;
#include <list>
/*
list容器：
功能：将数据进行链式存储

链表：物理存储单元上的非连续的存储结构 数据元素的逻辑顺序是通过链表中的指针链接实现

链表：由一系列结点组成

结点的组成结构：一个存储数据元素的数据域，另一个是存储下一个结点的指针域

STL中的链表是一个双向循环链表，一个元素中具有两个指针，一个指向前向元素的地址，一个指向后续元素
的地址。最后一个节点的next指向最开始元素，最开始元素的prev指向最后一个元素。

优点：可对任意位置进行快速插入和删除
缺点：遍历速度，没有数组快，占用空间比数组更大

链表list中的迭代器只支持前移和后移，属于双向迭代器

list插入操作和删除操作都不会造成原有list迭代器的失效，这在vector中是不成立的:
在list中插入和删除都不会使其它元素的数据和地址失效，而在vector中，若插入数据量大于
vector容量，它会重新开辟内存空间，造成原有数据指向一个新的地址

构造函数：
创建list容器
1:list<T>lst;list采用模板类实现对象的默认构造形式
2 list(beg,end); 构造函数将[beg,end)区间的元素拷贝到本身
3 list(n,elem);构造函数将n个elem拷贝给本身
4 list(const list &lst);拷贝构造函数
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// 创建list容器
	list<int>L1;// 默认构造

	// 添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// 遍历容器
	printList(L1);


	// 区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	// 拷贝构造
	list<int>L3(L2);
	printList(L3);

	// n个elem
	list<int>L4(10, 1000);
	printList(L4);
}


int main()
{
	test1();
	system("pause");

	return 0;
}
