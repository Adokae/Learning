# include <iostream>
using namespace std;
/*
主要针对泛型编程与STL技术进行讲解

模板就是通用模具

C++提供两种模板机制：函数模板和类模板

函数模板作用：建立一个通用函数，其函数返回值类型和形参类型不具体指定，
可以用一个虚拟的类型来表示

语法：
template<typename T>
template--声明创建模板
typename--表明其后面的符号是一种数据类型，可以用class代替
T--通用的数据类型，名称可以替换，通常为大写字母

函数模板注意事项：
1 自动类型推导，必须推导出一致的数据类型T，才可以使用
2 模板必须要确定T的数据类型，才可以使用
*/

//函数模板

//两个整型交换数据
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//交换两个浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T> // 声明一个模板 
//告诉编译器后面代码中紧跟着的T不要报错 T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void test1()
{
	int a = 10;
	int b = 5;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//swapInt(a, b);
	// 利用函数模板实现函数
	// 两种方式使用函数模板
	// 1 自动类型推导
	//mySwap(a, b);
	// 2 显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 1.1;
	double d = 5.5;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	swapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
