# include <iostream>
using namespace std;
#include<set>
/*
set/multiset容器

基本概念：
1 所有元素都会在插入时自动排序
本质：set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：
1 set不允许容器中有重复的元素
2 multiset允许容器中有重复的元素


set创建与赋值：
构造：
1 set<T> st;默认构造函数
2 set(const set &st);拷贝构造函数

赋值：
set& operator=(const set &st)重载等号操作符
*/

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	set<int>s1;

	// 插入数据 只有insert方式
	// set容器插入时自动排序
	// set容器不允许插入重复值
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	
	s1.insert(40);
	s1.insert(30);

	printSet(s1);

	// 拷贝构造
	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s1;
	printSet(s3);

}

int main()
{
	test1();
	system("pause");

	return 0;
}
