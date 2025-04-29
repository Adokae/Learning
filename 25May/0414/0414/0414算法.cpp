# include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
/*
算法主要有头文件<algorithm> <functional> <numerical> 组成
1<algorithm>是所有STL头文件中最大的一个 范围涉及到比较、交换、查找、遍历操作、复制、修改等
2<functional> 体积很小，只包含几个在序列上面进行简单数学运算的模板函数
3<numerical> 定义一些模板类，用以声明函数对象

常用遍历算法：
1 for_each 遍历容器
for_each(iterator beg, iterator end, _func)
 iterator beg:开始迭代器
 iterator end：结束迭代器
 _func函数或函数对象


2 transform 搬运容器到另一个容器中
*/

// 遍历算法 for_each
void print1(int val)
{
	cout << val << " ";
}

class print2
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
	// 法1 通过普通函数 放函数名
	for_each(v.begin(), v.end(), print1);
	cout << endl;

	// 法2 通过仿函数 放函数对象
	for_each(v.begin(), v.end(), print2());
	cout << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
