# include <iostream>
using namespace std;

/*
程序运行后：
栈区：由编译器自动分配释放，存放函数的参数值、局部变量等
注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
*/

int* func()
{
	int a = 10; // 局部变量 
	//该局部变量存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;
}
int main()
{
	int* p = func();
	cout << *p << endl; // 第一次打印正确，因为编译器做了保存
	cout << *p << endl;// 第二次数据不在保留 ？ 问题是此处打印还是正确的
	// 可能是编译器优化，暂时保存
	system("pause");

	return 0;
}
