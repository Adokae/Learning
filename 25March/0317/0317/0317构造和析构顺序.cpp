# include <iostream>
using namespace std;
/*
子类继承父类后，当创建子类对象，也会调用父类的构造函数
继承中的构造和析构顺序如下：
先构造父类，在构造子类，
析构顺序与构造顺序相反
*/
class Base
{
public:
	Base()
	{
		cout << "Base的构造函数" << endl;
	}
	~Base()
	{
		cout << "Base的析构函数" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son的构造函数" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数" << endl;
	}
};
void test1()
{
	//Base b;
	Son s;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
