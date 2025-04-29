# include <iostream>
using namespace std;
/*
C++中struct与class唯一的区别就在于默认的访问权限不同
区别：
struct:默认权限为公共
class:默认权限为私有
*/
class C1
{
	int m_A; // 默认私有
};

struct C2
{
	int m_B;
};

int main()
{
	C1 c1;
	// class默认私有 以下代码报错
	//c1.m_A = 100;
	C2 c2;
	c2.m_B = 100;
	cout << c2.m_B << endl;
	system("pause");

	return 0;
}
