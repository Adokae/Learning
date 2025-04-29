# include <iostream>
using namespace std;

/*
函数重载注意事件：
1 引用作为重载条件
2 函数重载碰到函数默认参数
*/

//1 引用作为重载条件
void func(int &a) // int &a = 10; 非法
{
	cout << "func(&a) 引用" << endl;
}
void func(const int& a)// const int &a = 10; 合法
{
	cout << "func const (&a) 引用" << endl;
}
// 2 函数重载碰到函数默认参数
void func2(int a, int b=10)
{
	cout << "func2 int a int b" << endl;
}
void func2(int a)
{
	cout << "func2 int a" << endl;
}
int main()
{
	int a = 10;
	func(a);

	func(10); // 调用const类型的func

	//func2(10); 函数重载遇到默认参数，出现二义性，报错，应尽量避免
	system("pause");

	return 0;
}
