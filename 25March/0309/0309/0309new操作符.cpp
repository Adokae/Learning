# include <iostream>
using namespace std;

/*
new操作符：可以在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
语法： new 数据类型
利用new创建的数据，会返回该数据对应的类型的指针
*/

int* func()
{
	// 在堆区创建整型数据
	int* p = new int(10);
	return p;
}

void test1()
{
	// 堆区数据由程序员管理
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	// 释放堆区数据 利用关键字delete
	delete p;
	// cout << *p << endl; // 内存已被释放，再次访问，报错
}

// 在堆区开辟数组
void test2()
{
	// 在堆区创建10个整型数组
	int * arr = new int[10];//[]表示创建数组
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	// 释放堆区数组 释放数组要加[]
	delete[] arr;
}

int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}
