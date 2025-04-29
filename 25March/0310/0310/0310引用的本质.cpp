# include <iostream>
using namespace std;

/*
引用的本质在C++内部是一个指针常量
引用一旦初始化，不可以发生改变-》指针指向不可以改变
*/
void func(int& ref)
{
	ref = 100;
}

int main()
{
	int a = 10;
	// 本质是int * const ref = &a;
	// 指针常量是指针指向不可以更改
	// 指针指向的值可以更改
	int& ref = a;

	// 实际是*ref = 20; 修改指针指向的值
	ref = 20;
	cout << "a=" << a << endl;
	cout << "ref=" << ref << endl;
	system("pause");

	return 0;
}
