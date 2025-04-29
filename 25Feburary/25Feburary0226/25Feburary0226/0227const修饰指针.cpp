# include <iostream>
using namespace std;

/*
const修饰指针有以下三种情况：
1 const修饰指针 --常量指针
特点： 指针的指向可以修改，但指针指向的值不可以改
2 const修饰常量 --指针常量
特点：指针的指向不可以改，但指针指向的值可以修改
3 const既修饰指针 又修饰常量 
特点：指针的指向和指针指向的值都不可以修改
*/
int main()
{
	// 1 常量指针
	int a = 10;
	int b = 10;
	const int * p = &a;
	//*p = 20;  错误
	p = &b;

	// 2 指针常量
	int* const p2 = &a;
	*p2 = 100;

	// 3 const既修饰指针 又修饰常量
	const int* const p3 = &a;
	// *p3 = 100; 错误

	system("pause");

	return 0;
}