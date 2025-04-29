# include <iostream>
using namespace std;
const double PI = 3.14;
/*
C++面向对象三大特性：封装、继承、多态

C++：万事万物皆对象，对象有其属性和行为

类：具有相同性质的对象

封装意义：
1 将属性和行为作为一个整体，表现生活中的事物
2 将属性和行为加以权限控制
*/

// 设计一个圆类，求圆的周长
// class表示设计一个类，类后面紧着类名称
class Circle
{
	// 访问权限
	// 公共权限
public:
	// 属性：半径
	int m_r;
	// 行为：获取圆的周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}

};
int main()
{
	// 通过圆类创建具体对象
	// 实例化-通过一个类创建一个对象
	Circle cl;
	// 给圆对象的属性进行赋值

	cl.m_r = 10;

	cout << "圆的周长" << cl.calculateZC() << endl;
	system("pause");

	return 0;
}
