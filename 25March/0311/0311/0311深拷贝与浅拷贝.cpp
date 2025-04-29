# include <iostream>
using namespace std;

/*
浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作

如果属性有在堆区开辟的，一定要自己提供拷贝构造函数
解决浅拷贝带来的问题
*/
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_age = age;
		Height = new int(height);
	}

	// 深拷贝
	Person(const Person& p)
	{
		cout << "Person拷贝构造函数的调用" << endl;
		m_age = p.m_age;
		//Height = p.Height; 这一行代码是编译器默认执行的代码

		// 深拷贝
		Height = new int(*p.Height);
	}
	~Person()
	{
		// 析构函数 将堆区开辟数据做释放操作
		if (Height != NULL)
		{
			delete Height;
			Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_age;
	int* Height;
};
void test1()
{
	Person p1(18, 160);
	cout << "p1的年龄： " << p1.m_age << "身高为：" << *p1.Height<< endl;
	// 浅拷贝 p2先释放堆区内存 p1释放时会出现报错 因为他们存储的是同一区域
	// 浅拷贝带来的问题就是堆区内存的重复释放
	Person p2(p1);
	cout << "p2的年龄： " << p2.m_age << "身高为：" << *p1.Height<< endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
