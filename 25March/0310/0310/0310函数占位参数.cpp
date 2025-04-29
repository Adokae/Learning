# include <iostream>
using namespace std;

/*
函数形参列表里可以有占位参数，用来做占位，调用函数是必须填补该位置
语法： 返回值类型 函数名(数据类型) {}
*/

// 占位参数
// 占位参数可以有默认参数
void func(int a, int = 10)
{
	// 第二个int表示占位
	cout << "this is a function " << endl;
}
int main()
{
	func(10, 10); // 输入函数的对应的占位参数无法使用
	system("pause");

	return 0;
}
