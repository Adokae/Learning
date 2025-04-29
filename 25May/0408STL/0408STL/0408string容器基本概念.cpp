# include <iostream>
using namespace std;
/*
string是C++风格的字符串 本质上是一个类

string 与char *的区别：
char *是一个指针
string是一个类 类内部封装了char* 管理该字符串 是一个char*型的容器

特点：
string类内部封装了很多成员方法
例如：查找find 拷贝copy 删除delete 替换replace 插入insert

string管理char*所分配的内存 不用担心复制越界和取值越界等 由类内部进行负责

string构造函数：
1 string(); 创建一个空的字符串
2 string(const char* s); 使用字符串s初始化
3 string(const string& str)； 使用一个string对象初始化另一个string对象
4 string(int n, char c); 使用n个字符c初始化

*/

void test1() {
	string s1;// 第一种构造方法

	const char* str = "hello world";// 第二种构造方法
	string s2(str);
	cout << "s2 = " << s2 << endl;

	// 第三种构造方法
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}
