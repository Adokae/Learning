# include <iostream>
using namespace std;
#include <set>
/*
set容器默认排序规则为从小到大，利用仿函数，改变排序规则

*/
class myCompare
{
public:
	// 第一个小括号表示要重载的符号 第二个小括号表示参数列表

	// 需要加const 不加const 遍历容器时 仿函数试图修改它的this指针 违反了const_iterator的约束
	// 导致编译错误 但我不加const时也报错了
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};



void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// 默认排序规则从小到大 改变排序规则 从大到小
	set<int, myCompare>s2;

	s2.insert(10);
	s2.insert(40);
	s2.insert(30);
	s2.insert(20);
	for (set<int, myCompare>::const_iterator it = s2.begin(); it != s2.end(); it++)
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
