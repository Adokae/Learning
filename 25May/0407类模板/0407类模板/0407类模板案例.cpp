# include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>
/*
类模板案例：
实现一个通用数组类，实现以下要求：
1 可以对内置数据类型以及自定义数组类型的数据进行存储
2 将数组中的数据存储到堆区
3 构造函数中可以传入数组的容量
4 提供对应的拷贝构造函数以及operator-防止浅拷贝问题
5 提供尾插法和尾删法对数组中的数据进行增加和删除
6 可以通过下标的方式访问数组中的元素
7 可以获取数组中当前元素的个数和数组的容量
*/

void printIntArray(MyArray<int> & arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test1()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：" << endl;
	printIntArray(arr1);
	cout << "arr1的容量为:" << arr1.getCapacity() << endl;
	cout << "arr1的大小为:" << arr1.getSize() << endl;

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "arr2的尾删后的打印输出为：" << endl;
	printIntArray(arr2);
	
	/*MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;*/
}
// 测试自定义数据类型
class Person
{
public:
	Person()
	{

	};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name = " << arr[i].m_Name << endl;
		cout << "age = " << arr[i].m_Age << endl;
	}
}
void test2()
{
	MyArray<Person> arr(10);
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);

	cout << "数组容量为" << arr.getCapacity() << endl;
	cout << "数组大小为" << arr.getSize() << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
