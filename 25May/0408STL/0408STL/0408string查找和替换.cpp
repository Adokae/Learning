# include <iostream>
using namespace std;

/*
查找：查找指定字符串是否存在
替换：在指定位置替换字符串

函数：
1 int find(const string& str, int pos = 0) const;//查找str第一次出现位置 从pos开始查找
2 int find(const char* s, int pos = 0) const;// 查找s第一次出现位置 从pos开始查找
3 int find(const char* s, int pos = 0, int n) const;// 从pos位置查找s的前n个字符第一次出现的位置
4 int find(const char c, int pos = 0) const;// 查找c第一次出现位置
5 int rfind(const string& str, int pos = npos) const;// 查找str最后出现位置 从pos开始查找
6 int rfind(const char *s, int pos = npos) const;// 查找s最后出现位置 从pos开始查找
7 int rfind(const char *s, int pos , int n) const;// 从pos位置查找s的前n个字符最后一次出现的位置
8 int rfind(const char c, int pos = 0) const;// 查找字符c最后一次出现的位置
9 string&  replace(int pos, int n , const string& str);// 替换从pos开始n个字符为字符串str
10string&  replace(int pos, int n , const char* s);// 替换从pos开始n个字符为字符串s
*/

// 查找
void test1() {
	string str1 = "abcdefghde";
	int pos = str1.find("de");// 存在 返回位置 不存在 返回-1
	if (pos == -1) {
		cout << "未找到该字符串" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	
	// rfind从右边往左开始查  find从左边往右开始查 
	int rpos = str1.rfind("de");
	cout << "rpos = " << rpos << endl;
}


// 替换
void test2() {
	string str1 = "abcdefg";
	str1.replace(1, 2, "1111");
	// 从第一个索引位置开始起2个字符 替换为"1111"
	cout << "str1 = " << str1 << endl;
}


int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
