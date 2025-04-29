# include <iostream>
using namespace std;
/*
多态中，父类虚函数实现无意义，可将虚函数改为纯虚函数
纯虚函数语法： virtual 返回值类型 函数名 （参数列表）= 0;
类中有了纯虚函数，类也称为抽象类

抽象类特点：
1 无法实例化对象
Base = b; new Base; 都是错误的
2 子类必须重写抽象类中的纯虚函数 否则也属于抽象类
不重写 Son s;报错
*/

class Base
{
public:
	// 纯虚函数
	virtual void func() = 0;
	// 该类为抽象类
};
class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func函数调用" << endl;
	}
};

void test1()
{
	Base* base = new Son;
	base->func();
}

int main()
{
	test1();
	system("pause");

	return 0;
}
