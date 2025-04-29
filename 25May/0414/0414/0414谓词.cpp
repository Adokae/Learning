# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
谓词概念：
1 返回bool类型的仿函数称为谓词
2 若operator()接收一个参数，称为一元谓词
3 若operator()接收两个参数，称为二元谓词

*/
// 一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找容器中大于5的数字
	// find_if中的GreaterFive()为匿名函数对象
	vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字为：" << *it << endl;
	}
}
int main()
{
	test1();
	system("pause");

	return 0;
}
