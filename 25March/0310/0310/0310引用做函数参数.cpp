# include <iostream>
using namespace std;
/*
引用做函数参数：
函数传参时，可以利用引用技术让形参修饰实参
优点：可以简化指针修改实参
*/
// 交换函数
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 地址传递
void Swap2(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 引用传递 引用变的就是实参的值
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap1(a, b); // 值传递，形参不会修饰实参
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	Swap2(&a, &b); // 地址传递，形参会修饰实参
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	// 此处输入的a b值为20 10
	Swap3(a, b); // 引用传递，形参会修饰实参
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	system("pause");

	return 0;
}
