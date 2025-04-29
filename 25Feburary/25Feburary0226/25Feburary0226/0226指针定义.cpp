# include <iostream>
using namespace std;

/*
指针作用：可以通过指针间接访问内存
内存编号从0开始，一般用十六进制数字表示
可以用指针变量保存地址（内存地址）

指针变量定义语法： 数据类型 * 变量名;
*/

/*
指针也是种数据类型，
在32位操作系统下，指针占用4个字节空间
在64位操作系统下，指针占用8个字节空间
*/
int main()
{
	// 定义指针
	int a = 10;
	int * p;
	// 让指针记录变量a的地址
	p = &a;

	// int * p = &a;

	cout << "a的地址" << &a << endl;
	cout << "指针p为" << p << endl;
	*p = 1000;
	cout << "a=" << a << endl;
	cout << "*p为" << *p << endl;
	// 使用指针
	// 可以通过解应用的方式找到指针指向的内存地址
	// 指针前加 * 表示解引用 找到指针指向内存中的数据

	// 指针所占内存空间大小
	cout << "sizeof (int *)=" << sizeof(p) << endl;

	cout << "sizeof (int *)=" << sizeof(int *) << endl;
	cout << "sizeof (double *)=" << sizeof(double *) << endl;
	cout << "sizeof (char *)=" << sizeof(char *) << endl;

	system("pause");

	return 0;
}