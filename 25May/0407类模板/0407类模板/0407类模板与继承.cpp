# include <iostream>
using namespace std;
/*
类模板与继承：
1 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
2 若不指定，编译器无法给子类分配内存
3 若想灵活指定出父类中T的类型 子类也需要变成类模板
*/

template<class T>
class Base
{
	T m;
};

//class son :public Base// 报错 必须知道父类中T的数据类型
class Son:public Base<int>
{

};

void test1()
{
	Son s1;// 能够正常实例化对象
}

//想灵活指定父类中的T类型，子类也需要变类模板
template<class T1, class T2>
class Son2 :public Base<T2>// 指定父类中的数据类型为T2
{
public:
	Son2()
	{
		cout << "T1的数据类型" << typeid(T1).name() << endl;
		cout << "T2的数据类型" << typeid(T2).name() << endl;
	}
	T1 obj;// 子类的数据类型为T1
};

void test2()
{
	Son2<int, char>S2;// int传给T1 char传给T2
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
