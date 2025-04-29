# include <iostream>
using namespace std;

/*
函数对象：
概念：重载函数调用操作符的类，其对象常称为函数对象
函数对象使用重载的()时，行为类似函数调用，也叫仿函数

本质：函数对象(仿函数)是一个类，不是一个函数

使用：
1 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
2 函数对象超出普通函数的概念，函数对象可以有自己的状态
3 函数对象可以作为参数传递

*/
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

// 用法1 像普通函数那样调用
void test1()
{
	MyAdd myAdd;// 通过类创建对象
	cout << myAdd(10, 10) << endl;

}

// 用法2 函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count; // 内部自己的状态
};

void test2()
{

	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数：" << myPrint.count << endl;
}

// 用法3 函数对象可以作为参数传递
void doPrint(MyPrint& m, string test)
{
	m(test);
}

void test3()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello World");
}


int main()
{
	//test1();
	//test2();
	test3();
	system("pause");

	return 0;
}
