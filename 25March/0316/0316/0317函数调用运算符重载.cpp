# include <iostream>
using namespace std;

/*
函数调用运算符()重载
重载后使用的方式非常像函数的调用，因此称为仿函数
仿函数非常灵活，没有固定写法
*/

// 打印输出类
class MyPrint
{
public:
	// 重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint2(string test)
{
	cout << test << endl;
}

void test1()
{
	MyPrint myPrint;
	myPrint("hello world");// 仿函数
	MyPrint2("hello ");
}

// 加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test2()
{
	MyAdd myadd;
	int ret = myadd(100, 200);
	cout << "ret = " << ret << endl;

	// 匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}
