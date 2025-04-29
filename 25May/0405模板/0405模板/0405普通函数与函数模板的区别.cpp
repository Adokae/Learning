# include <iostream>
using namespace std;
/*
普通函数与函数模板的区别：
1 普通函数调用时可以发生自动类型转换(隐式类型转换)
2 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
3 如果利用显示指定类型的方式，可以发生隐式类型转换
*/

// 普通函数
int myAdd(int a, int b)
{
	return a + b;
}
// 函数模板
template<typename T>
T myAdd1(T a, T b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//cout << myAdd(a, b) << endl;
	cout << myAdd(a, c) << endl;// 发生隐式类型转换 转换成'c'的ASCII码

	// 使用函数模板
	cout << myAdd1(a, b) << endl; // 自动类型推导
	//cout << myAdd1(a, c) << endl; // 自动类型推导 报错

	cout << myAdd1<int>(a, c) << endl; // 自动类型推导
}
int main()
{
	test1();
	system("pause");

	return 0;
}
