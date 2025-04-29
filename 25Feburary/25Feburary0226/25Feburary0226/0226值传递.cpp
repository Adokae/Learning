# include <iostream>
using namespace std;
/*
值传递：
函数调用时实参将数值传递给了形参
值传递时，如果形参发生变化，不会影响实参
*/

// 编写函数实现两个数字交换
// 若函数不需要返回值，声明的时候写void,函数中不写return或只写return

void swap(int num1, int num2)
{
	cout << "交换前" << endl;
	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "交换后" << endl;
	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	swap(a, b);
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	// 实参值a b不会发生变化
	system("pause");
	return 0;
}
