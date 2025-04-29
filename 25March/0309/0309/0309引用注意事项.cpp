# include <iostream>
using namespace std;

/*
引用注意事项：
1 引用必须初始化
2 引用在初始化后，不可以改变
*/
int main()
{
	int a = 10;
	int& b = a;
	// 应用必须初始化
	// 错误实例
	// int &c;

	//引用在初始化后，不可以改变
	int b = 100;

	system("pause");

	return 0;
}
