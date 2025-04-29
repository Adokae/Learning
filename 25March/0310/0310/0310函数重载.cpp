# include <iostream>
using namespace std;

/*
函数重载：
作用：函数名可以相同，提高复用性

函数重载满足条件：
1 同一个作用域下
2 函数名称相同
3 函数参数 类型不同或个数不同或顺序不同

注意：函数的返回值不可以作为函数重载的条件
*/

// 条件1
void func()
{
	cout << "this is a fuction" << endl;
}

void func(int a)
{
	cout << "this is int a fuction!" << endl;
}
void func(double a)
{
	cout << "this is double a fuction!!" << endl;
}
void func(double a, int b)
{
	cout << "this is double a int b fuction!!" << endl;
}
void func(int a, double b)
{
	cout << "this is int a double b fuction!!" << endl;
}
// 错误示例 函数返回值作为函数重载的条件
//int func(int a, double b)
//{
//	cout << "this is int a double b fuction!!" << endl;
//}
int main()
{
	func(2, 10.1);
	system("pause");

	return 0;
}
