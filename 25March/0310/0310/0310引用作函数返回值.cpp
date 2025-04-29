# include <iostream>
using namespace std;

/*
引用作函数返回值：
注意：不要返回局部变量引用
用法:函数调用作为左值
*/
// 错误示例
int& test1()
{
	int a = 10;
	return a;
}

// 函数调用作为左值
int& test2()
{
	static int a = 10; // 静态变量，存放在全局区，
	//程序结束后由系统释放
	return a;
}
int main()
{
	//int& ref = test1();
	//cout << "ref=" << ref << endl; // 出错

	int& ref2 = test2();
	cout << "ref2=" << ref2 << endl; 

	// 函数的返回值是引用，函数的调用可以作为左值
	// test2()返回的是a的引用，将1000复制给a的引用，
	// ref2是a的别名 改a的引用就更改了原来的ref2值
	test2() = 1000;
	cout << "ref2=" << ref2 << endl; // 出错
	system("pause");

	return 0;
}
