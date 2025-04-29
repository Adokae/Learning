# include <iostream>
using namespace std;
#include <string>
/*
虚析构和纯虚析构的使用：多态使用时，如果子类中有属性开辟到堆区，
那么父类指针在释放时无法调用到子类中的析构代码，就需要使用虚析构和纯虚析构

解决方式：将父类中的析构函数改为纯析构或纯虚析构

虚析构和纯虚析构共性：
1 可解决父类指针释放子类对象
2 都需要有具体的函数体现

虚析构和纯虚析构区别：
如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法： vitrual ~类名(){}
纯虚析构语法：virtual ~类名() = 0;

子类中没有堆区数据 可以不写虚析构或纯虚析构
*/

class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	virtual void speak() = 0;
	// 虚析构解决父类指针释放子类对象不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal析构函数调用" << endl;
	}*/

	// 纯虚析构 但若只有下面一行代码 报错 因为需要代码实现
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name = new string(name);
	}

	virtual void speak()
	{
		cout << *m_Name << "猫叫" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string *m_Name;
};

void test1()
{
	Animal* animal = new Cat("Tom"); // 使用基类指针创建派生类对象
	// 利用动态绑定，程序在运行时决定调用那个类的方法
	animal->speak();
	// 父类指针在析构时 不会调用子类中析构函数
	// 导致子类如果有堆区数据 造成内存泄露
	delete animal;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
