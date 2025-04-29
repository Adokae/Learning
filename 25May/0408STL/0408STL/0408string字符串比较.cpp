# include <iostream>
using namespace std;
/*
字符串比较：
 按字符的ASCII码进行比较
 = 0
 > 1
 < -1

 函数:
 1 int compare(const string &s) const;//与字符串s比较
 2 int compare(const char *s);//与字符串s比较
*/

void test1()
{
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "str1 = str2" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "str1 > str2" << endl;
	}
	else if (str1.compare(str2) < 0) {
		cout << "str1 < str2" << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}
