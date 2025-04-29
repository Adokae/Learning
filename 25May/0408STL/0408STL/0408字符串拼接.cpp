# include <iostream>
using namespace std;

/*
实现在string末尾拼接字符串

函数：
1 string& operator+=(const char* str);//重载+=操作符
2 string& operator+=(const char c);// 重载+=操作符
3 string& operator+=(const string& str);// 重载+=操作符
4 string& append(const char* s);// 把字符串s 连接到当前的字符串结尾
5 string& append(const char* s, int n);// 把字符串s的前n个字符连接到当前的字符串结尾
6 string& append(const string &s);// 同operator+=(const string& str)
7 string& append(const string &s,int pos, int n);// 字符s中从pos开始的n个字符连接到字符串结尾
*/

void test1() {
	string str1 = "I";
	str1 += " am";
	cout << "str1 = " << str1 << endl;

	str1 += ":";
	cout << "str1 = " << str1 << endl;

	string str2 = " a b c d";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << "str3 = " << str3 << endl;

	str3.append("blue sky aaaaa", 8);
	cout << "str3 = " << str3 << endl;

	str3.append(str2);
	cout << "str3 = " << str3 << endl;

	str3.append(str2, 0, 3);// 指定截取字符串 0表示开始截取的位置 3表示截取的元素
	cout << "str3 = " << str3 << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}
