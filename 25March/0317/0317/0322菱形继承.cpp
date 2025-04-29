# include <iostream>
using namespace std;

/*
菱形继承概念：
两个派生类继承同一个基类，又有某个类同时继承两个派生类
*/

class Animal
{
public:
	int m_Age;
};

// 虚继承 
/*
继承之前 加上关键字 virtual变成虚继承
Animal类称为虚基类

加虚继承后 SheepTuo继承的是Animal中的m_Age 
vbptr:虚基类指针 加虚继承后 SheepTuo继承的是两个指针 
两个指针通过偏移量都指向为唯一的数据
*/
class Sheep:virtual public Animal {};

class Tuo:virtual public Animal {};

class SheepTuo:public Sheep,public Tuo{};

void test1()
{
	SheepTuo st;
	// 菱形继承 两个父类具有相同数据 需要加作用域区分
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	// 虚继承之后年龄都变成28
	// 两份数据 资源浪费 虚继承解决
	cout << "Sheep中的Age " << st.Sheep::m_Age << endl;
	cout << "Tuo中的Age " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
