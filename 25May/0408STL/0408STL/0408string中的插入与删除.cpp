# include <iostream>
using namespace std;
/*
string中的插入与删除:
对string字符串进行插入和删除字符的操作

函数：
1 string& insert(int pos, const char * s);//插入字符串
2 string& insert(int pos, const string& str);//插入字符串
3 string& insert(int pos, int n, char c);//在指定位置插入n个字符c
4 string& erase(int pos, int n = pos);//删除从pos开始的n个字符
*/

void test1() {
	string str1 = "hello";
	// 插入
	str1.insert(1, "111");
	cout << "str1 = " << str1 << endl;

	// 删除
	str1.erase(1, 3);
	cout << "str1 = " << str1 << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}
