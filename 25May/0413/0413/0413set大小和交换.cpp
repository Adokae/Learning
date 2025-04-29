# include <iostream>
using namespace std;
#include <set>
/*
set大小和交换

函数：
1 size()  返回容器中元素数目
2 empty() 判断容器是否为空
3 swap()   交换两个集合容器

*/
void printSet(const set<int> & S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



// 大小
void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);

	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}

// 交换
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);

	cout << "交换前：" << endl;
	printSet(s1);
	printSet(s2);

	s1.swap(s2);
	cout << "交换后：" << endl;
	printSet(s1);
	printSet(s2);

}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
