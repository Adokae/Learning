# include <iostream>
using namespace std;
#include <string>
/*
成员属性设置为私有：
优点
1：将所有成员属性设置为私有，可以自己控制读写权限
2 对于写权限，可以检测数据的有效性
*/

class Person
{
public:
	void setName(string name)
	{
		Name = name;
	}
	string getName()
	{
		return Name;
	}
	int getAge()
	{
		return Age;
	}
	void setIdol(string idol)
	{
		Idol = idol;
	}
	void setAge(int age)
	{
		if (age < 0 || age >150)
		{
			cout << "年龄赋值失败" << endl;
			return;
		}
		Age = age;
	}
private:
	string Name; // 可读可写
	int Age = 18; // 只读 但将年龄限制在0到150之间
	string Idol; //只写
};
int main()
{
	Person p;
	p.setName("Jack");
	cout << p.getName() << endl;
	//p.Name = "Jack";
	// 获取年龄
	// 只读
	cout << p.getAge() << endl;

	// 只写
	p.setIdol("lisi");

	p.setAge(160);
	cout << p.getAge() << endl;
	system("pause");

	return 0;
}
