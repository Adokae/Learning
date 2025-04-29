# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
transform：搬运容器到另一个容器中

函数：
transform(iterator beg1,iterator end1, iterator beg2, _func);
beg1 源容器开始迭代器
end1 源容器结束迭代器
beg2 目标容器开始迭代器
_func 函数或函数对象

*/
class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
};

class print1
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	// 搬运容器必须提前开辟内存空间
	vTarget.resize(v.size());

	transform(v.begin(), v.end(), vTarget.begin(), Transform());// 在转移过程中可做一些转移运算
	
	for_each(vTarget.begin(), vTarget.end(), print1());
	cout << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
