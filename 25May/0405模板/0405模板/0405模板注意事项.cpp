# include <iostream>
using namespace std;

/*
函数模板注意事项：
1 自动类型推导，必须推导出一致的数据类型T，才可以使用
2 模板必须要确定除T的数据类型，才可以使用
*/
template<typename T> // typename可以换成class

void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	cout << "a = " << endl;
	cout << "b = " << endl;
	//mySwap(a, b);
	//注意事项1
	//mySwap(a, c); // 报错 推导出不一致的数据类型
	cout << "a = " << endl;
	cout << "b = " << endl;
}
//注意事项2
template<typename T>
void func()
{
	cout << "func 调用" << endl;
}
void test2()
{
	//func(); // 报错
	func<int>();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
