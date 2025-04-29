# include <iostream>
using namespace std;
/*
函数默认参数：函数形参列表中的形参是可以有默认值的
语法:返回值类型 函数名 （参数=默认值）{}

若有输入数据，使用输入数据；未输入数据，使用默认值

注意事项：
1 若某个位置已经有了默认值，则从该位置往后，从左到右都必须有默认值
2 若函数声明有默认参数 函数实现就不能有默认参数
声明和实现只能有一个默认参数
*/
int func(int a, int b = 20, int c = 20)
{
	return a + b + c;
}

int func2(int a = 10, int b=20);

int func2(int a , int b)
{
	return a + b;
}

int main()
{
	cout << func(10) << endl;
	cout << func2(10, 20) << endl;
	system("pause");

	return 0;
}
