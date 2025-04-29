# include <iostream>
using namespace std;
/*
构造函数的分类及调用：
两种分类方式：
按参数分：有参构造与无参构造
按类型分：普通构造和拷贝构造

三种调用方式：
括号法
显示法
隐式转换法
*/
class Person
{
public:
	// 有参构造和无参构造
	// 普通构造
	Person()
	{
		cout << "调用无参构造函数" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "调用有参构造函数" << endl;
	}
	// 拷贝构造函数
	Person(const Person &p)
	{
		// 将传入参数的所有属性，拷贝到另一个参数上
		cout << "调用拷贝构造函数" << endl;
		age = p.age;
	}

	~Person()
	{
		cout << "调用析构函数" << endl;
	}
	int age;
};

// 调用
void test1()
{
	// 括号法
	//Person p1;// 默认构造函数调用
	//Person p2(10); // 有参构造函数调用
	//Person p3(p2); // 拷贝构造函数调用
	// 注意事项
	// 调用默认构造函数的时候,不要加小括号()
	// 下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	//Person p1();
	/*cout << "the age of p2 is " << p2.age << endl;
	cout << "the age of p3 is " << p3.age << endl;*/


	// 显示法
	//Person p1;// 默认构造函数调用
	//Person p2 = Person(10); // 有参构造函数调用
	//Person p3 = Person(p2); // 拷贝构造函数调用
	// 下面一行代码为匿名对象 
	// 特点是：当前行执行结束后，系统会立即回收掉匿名对象
	// Person(10)
	// 注意事项2 不要利用拷贝构造函数 初始化匿名对象
	// 编译器会认为 Person(p3) === Person p3;
	// Person(p3);
	
	// 隐式转换法
	Person p4 = 10; // 相当于Person p4 = Person(10);
	Person p5 = p4; // 拷贝构造

}

int main()
{
	test1();
	system("pause");

	return 0;
}
