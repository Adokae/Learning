# include <iostream>
using namespace std;

/*
常量引用主要用于修饰形参，防止误操作
在函数形参列表中，可以加const修饰形参，防止形参改变实参
*/

void Print(const int& val)
{
	// 加const防止在函数体内部修改数据
	cout << "val=" << val << endl;
}

int main()
{
	int a = 10;
	int& ref = a;// 引用必须引一块合法的内存空间，不能直接引常量
	// 错误示例
	//int& ref = 10;

	// 正确示例
	//加const 编译器将下面代码改为 
	//int temp = 10; const int &ref = temp;
	// 但加入const后变为只读 不可以修改
	//const int& ref2 = 10;
	Print(a);
	system("pause");

	return 0;
}
