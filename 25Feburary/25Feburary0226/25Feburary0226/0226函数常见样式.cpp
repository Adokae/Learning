# include <iostream>
using namespace std;
/*
4种常见的函数样式：
1 无参无返
2 有参无返
3 无参有返
4 有参有返
*/

// 样式1
void type1()
{
	cout << "这是无参无返函数" << endl;
}

// 样式2
void type2(int a)
{
	cout << "这是有参无返函数" << endl;
	cout << "输出" << a << endl;
}

// 样式3
int type3()
{
	cout << "这是无参有返函数" << endl;
	return 100;
}

// 样式4
int type4(int b)
{
	cout << "这是有参有返函数" << endl;
	return b;
}
int main()
{

	//type1();

	int a = 10;
	type2(a);

	int num1 = type3();
	cout <<"类型3函数中的返回值为" << num1 << endl;

	int num2 = type4(1000);
	cout << "类型4函数中的返回值为" << num2 << endl;
	system("pause");

	return 0;
}