# include <iostream>
using namespace std;
/*
字符截取：
从字符串中获取想要的子串

函数：
string substr(int pos = 0,int n = npos) const; // 返回由pos开始的n个字符组成的字符串
*/

void test1() {
	string str1 = "abcdef";
	string subStr1 = str1.substr(1, 3);
	cout << "subStr1 = " << subStr1 << endl;
}


void test2() {
	string email = "Alice@sina.com";
	// 从email中获取用户名
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << "userName = " << userName << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
