# include <iostream>
using namespace std;

/*
类在设计时，可以把属性和行为放在不同的权限下，加以控制
访问权限有三种：
1 public 公共权限 类内可以访问 类外也可以访问
2 protected 保护权限 类内可以访问 类外不可以访问 
子类可以访问父类的保护内容
3 private 私有权限 类内可以访问 类外不可以访问
子类不可以访问父类的私有内容
*/

class Person
{
public:
	string Name;
protected:
	string Car;
private:
	int Password;
public:
	void func()
	{
		Name = "张三";
		Car = "小汽车";
		Password = 12345;
	}
};
int main()
{
	Person p1;
	p1.Name = "李四";
	// 私有权限/保护权限在类外不可以访问
	// 错误示例
	//p1.Car = 145;
	system("pause");

	return 0;
}
