# include <iostream>
using namespace std;
# include <string>
/*
C++类中的成员可以是另一个类的对象 称该成员为对象成员
当其它类对象作为本类成员，构造的时候先构造类对象，在构造自身
析构的顺序与构造相反

*/
// 例如：
// B类中有对象A作为成员 A为对象成员
class A{};
class B
{
	A a;
};

class Phone
{
public:
	Phone(string pName)
	{
		cout << "Phone的构造函数" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "Phone的析构函数" << endl;
	}
	string m_PName;
};

class Person
{
public:

	// Phone m_Phone = pName;
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person的构造函数" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数" << endl;
	}
	string m_Name;
	Phone m_Phone;
};

void test1()
{
	Person p("张三", "苹果");
	cout << p.m_Name << "拿着"  << p.m_Phone.m_PName << "手机" << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
