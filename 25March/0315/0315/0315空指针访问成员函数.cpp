# include <iostream>
using namespace std;
/*
空指针访问成员函数
*/
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		// 实际是this->age
		cout << "age = " << m_Age << endl;
	}
	int m_Age;
};

void test1()
{
	Person* p = NULL;
	//p->showClassName(); // 空指针可以访问

	// 下面这段报错
	// p设置为空，无法访问类中的属性 使用到this指针 
	// 就需要额外加代码保证代码的健壮性
	p->showPersonAge();
}
int main()
{
	test1();
	system("pause");

	return 0;
}
