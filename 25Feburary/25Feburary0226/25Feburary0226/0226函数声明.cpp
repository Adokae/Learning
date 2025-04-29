# include <iostream>
using namespace std;


/*
函数声明 提前告诉编译器函数的存在，可以利用函数的声明
通过函数的声明，可以将函数放在主函数后面
函数声明可以写多次，当时函数定义只能有一次
*/

// 实现两个整数的比较，返回较大值
int max(int a, int b);

int main()
{

	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;
	system("pause");

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;

}