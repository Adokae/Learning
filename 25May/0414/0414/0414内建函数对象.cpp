# include <iostream>
using namespace std;
#include <functional>
/*
STL内建一些函数对象

分类：
1 算术仿函数
2 关系仿函数
3 逻辑仿函数

仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需加入头文件#include<fuctional>

算术仿函数介绍：实现四则运算，只有negate为一元运算，其它都是二元运算
仿函数原型：
1 template<class T> T plus <T> 加法仿函数
1 template<class T> T minplus <T> 减法仿函数
1 template<class T> T multiplies <T> 乘法仿函数
1 template<class T> T divides <T> 除法仿函数
1 template<class T> T modulus <T> 取模仿函数
1 template<class T> T negate <T> 取反仿函数

*/

// negate 一元仿函数 取反
void test1()
{
	negate<int>n;
	cout << n(50) << endl;
}

// plus 二元仿函数 加法
void test2()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
