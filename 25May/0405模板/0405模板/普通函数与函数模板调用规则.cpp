# include <iostream>
using namespace std;
/*
普通函数和函数模板的调用规则
1 如果函数模板和普通函数都可以实现 优先调用普通函数
2 可以通过空模板参数列表来强制调用函数模板
3 函数模板也可以发生重载
4 如果函数模板可以产生更好的匹配 优先调用函数模板

既然提供了函数模板 最好就不要提供普通函数了 容易出现二义性
*/
void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

// 函数模板进行重写
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的函数模板" << endl;
}

void test1()
{
	int a = 10;
	int b = 20;
	//myPrint(a, b); // 调用普通函数 优先调用普通函数
	// 如果普通函数只有声明 没有实现 直接报错

	// 通过空模板参数列表 强制调用函数模板
	/*myPrint<>(a, b);

	myPrint<>(a, b, 100);*/

	// 如果函数模板产生更好的匹配 优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);// 调用模板 因为调用模板可以直接视为T为char类型
	// 而调用函数意味着还要发生隐式类型转换
}

int main()
{
	test1();
	system("pause");

	return 0;
}
