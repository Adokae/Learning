# include <iostream>
using namespace std;
#include <set>

/*
set与multiset的区别：
1 set不可以插入重复数据 multiset可以
2 set插入数据的同时会返回插入结果 表示插入是否成功
3 mutiset不会检测数据 因此可以插入重复数据

*/


void test1()
{
	set<int> s1;
	pair <set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
	s1.insert(20);

	multiset<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(10);
	for (multiset<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


int main()
{
	test1();
	system("pause");

	return 0;
}
