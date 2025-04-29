# include <iostream>
using namespace std;
/*
继承的子类无法访问父类的私有属性
继承方式：
1 公共继承
2 保护继承 父类中的公有属性和保护属性变为子类中的保护属性
3 私有继承 父类中的公有属性和保护属性变为子类中的私有属性
*/

// 公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员到子类中依然是公共权限
		m_B = 20;// 父类中的保护权限成员到子类中依然是保护权限
		//m_C = 10;// 父类中的私有权限成员 子类访问不到
	}
};

void test1()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; // 保护权限类外无法访问
}

// 保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员到子类中变为保护权限
		m_B = 20;// 父类中的保护权限成员到子类中依然是保护权限
		//m_C = 10;// 父类中的私有权限成员 子类访问不到
	}
};

// 私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 10;// 父类中的公共权限成员到子类中变为私有权限
		m_B = 20;// 父类中的保护权限成员到子类中变为私有权限
		//m_C = 10;// 父类中的私有权限成员 子类访问不到
	}
};
void test3()
{
	Son2 s3;
	//s1.m_A = 100;
	//s1.m_B = 100; // 保护权限类外无法访问
}


int main()
{
	test1();
	system("pause");

	return 0;
}
