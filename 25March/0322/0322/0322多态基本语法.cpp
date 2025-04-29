# include <iostream>
using namespace std;

/*
多态分类：
1 静态多态：函数重载和运算符重载属于静态多态 复用函数名
2 动态多态：派生类和虚函数实现运行时多态

两者区别：
静态多态的函数地址早绑定-编译阶段确定函数地址
动态多态的函数地址晚绑定-运行阶段确定函数地址

动态多态满足条件：
1 有继承关系
2 子类要重写父类中的虚函数
（重写 函数返回值类型 函数名 参数列表 完全相同）

动态多态使用：
父类的指针或者引用 指向子类对象

vfptr-虚函数(表)指针
vftable-虚函数表,表内部记录虚函数地址

当子类重写父类中的虚函数，子类中的虚函数表内部会替换成子类的虚函数地址
例如 父类中的地址为 &Animal::speak,子类中的地址为&Cat::speak
调用时：Animal & animal = cat；
*/

class Animal
{
public:
	// 加virtual关键字 使函数变为虚函数 编译器在编译的时候不能确定函数调用
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "小猫在叫" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "狗在叫" << endl;
	}
};
// 执行说话的函数
// 地址早绑定 在编译阶段确定函数地址 调用Animal类中方法
// 若想让猫说话 该函数地址不能提前绑定 需要在运行阶段进行绑定
// 地址晚绑定
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test1()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}

void test2()
{
	// 实函数大小为1个字节 加virtual变虚函数后变为4个字节
	cout << "sizeof of Animal is " << sizeof(Animal) << endl;
}
int main()
{
	test1();
	//test2();
	system("pause");

	return 0;
}
