# include <iostream>
using namespace std;
#include <string>
/*
string中单个字符存取方式有两种：
1 char & operator[](int n);// 通过[]方式取字符
2 char & at(int n);// 通过at方法取字符
*/

void test1()
{
	string str = "hello ";
	cout << "str = " << str << endl;

	// 通过[]访问单个字符
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;


	// 通过at方法取字符
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;


	// 修改字符串中的单个字符
	str[0] = 'x';
	cout << "str = " << str << endl;

	str.at(1) = 'x';
	cout << "str = " << str << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
