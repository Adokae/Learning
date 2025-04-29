# include <iostream>
using namespace std;

/*
函数定义一般包括以下步骤：
1 返回值类型
2 函数名
3 参数表列
4 函数体语句
5 return 表达式

语法：
返回值类型 函数名(参数列表)
{
	函数体
	return表达式
}

函数调用： 函数名称(参数)
*/

// 实现加法函数
// 函数定义时的num1, num2称为形参，只是形式上的参数
int add(int num1,int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main()
{
	int num1 = 2;
	int num2 = 6;
	// 此处的num1和num2为实参
	cout << add(num1, num2) << endl;
	system("pause");

	return 0;
}