# include <iostream>
using namespace std;
/*
三目运算符
表达式1？表达式2：表达式3
若表达式1为真，执行表达式2
若表达式1为假，执行表达式3
*/
int main()
{
	//创建三个变量 a b c
	// 将a和b做比较 将变量大的值赋值给变量c
	system("pause");
	int a = 10;
	int b = 20;
	int c = 0;
	a > b ? c = a : c = b;
	cout << "输出a和b之间的最大值" << c << endl;
	return 0;
}