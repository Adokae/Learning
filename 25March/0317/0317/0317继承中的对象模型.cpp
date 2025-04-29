# include <iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base
{
public:
	int m_D;
};

void test1()
{
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中私有成员属性 是被编译器隐藏了 但确实被继承下去了
	cout << "size of Son = " << sizeof(Son) << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
