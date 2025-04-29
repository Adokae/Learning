# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
容器：vector 
算法：for_each
迭代器：vector<int>::iterator
*/

// vector容器存放内置数据类型

void myPrint(int val)
{
	cout << val << endl;
}

void test1()
{
	vector<int> v; // 创建一个vector容器 数组 存放整型元素
	//插入元素
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//// 通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();// 起始迭代器 指向容器中的第一个元素
	//vector<int>::iterator itEnd = v.end(); // 结束迭代器 指向容器中最后一个元素的下一个位置
	//// 第一种遍历方式
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	// 第二种迭代方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	// 第三种迭代方式 利用STL提供遍历算法
	for_each(v.begin(),v.end(),myPrint);

}

int main()
{
	test1();
	system("pause");

	return 0;
}
