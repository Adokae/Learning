# include <iostream>
using namespace std;
/*
指针和函数：
利用指针作函数参数，可以修改实参的值
*/

// 代码实现两个数字之间的值交换
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int * p1, int * p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	swap1(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	// 地址传递
	// 地址传递 可以修改实参 改的是地址所指向的值
	swap2(&a, &b); // 地址传递
	cout << "进行地址传递后：" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");

	return 0;
}
