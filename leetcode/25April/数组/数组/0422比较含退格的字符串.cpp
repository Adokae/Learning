# include <iostream>
using namespace std;
#include <string>
#include <vector>
/*
1 思路1：先判断字符串的最终元素值，在对两个字符串进行比较
使用栈对元素进行操作，遍历字符串中元素值，若为#，栈不为空，删除栈顶元素，
若不为#，把当前元素插入栈中

2 看一个元素是否需要删除，看该元素后面是否具有退格符；因此考虑从后往前遍历元素，
用skip表示要删除元素的个数，从后往前遍历元素时，若遇到退格符，说明需要删除元素，
skip+1；若遇到普通元素，判断skip是否为0，skip为0，说明该元素不需要删除,skip不为0，说明
该元素需要删除;

*/
string backSpace(string s);

bool backspaceCompare(string s, string t)
{
	s = backSpace(s);
	t = backSpace(t);
	return (s == t);
}

string backSpace(string s)
{
	string ret;
	for (char ch : s) {
		if (ch != '#') {
			ret.push_back(ch);
		}
		else if (!ret.empty()) {
			ret.pop_back();
		}
	}
	return ret;
}

bool backspaceCompare2(string s, string t) {
	int i = s.length() - 1;
	int j = t.length() - 1;// 指向字符串最后一个元素
	int skipS = 0;
	int skipT = 0;
	while (i >= 0 || j >= 0) {
		while (i >= 0) {
			if (s[i] == '#') {
				// 字符串中元素为退格符 要删除的元素个数加1 元素索引值减1
				skipS++, i--;
			}
			else if (skipS > 0) {
				//元素为普通符号 且要删除的元素个数不为0 说明该元素需要删除
				// 删除该元素，元素索引值减1
				skipS--, i--;
			}
			else {
				// 元素为普通符号 且要删除的元素个数为0 说明该元素不需要删除
				// 跳出循环 当前索引i指向不需要删除的元素
				break;
			}
		}
		while (j >= 0) {
			if (t[j] == '#') {
				// 字符串中元素为退格符 要删除的元素个数加1 元素索引值减1
				skipT++, j--;
			}
			else if (skipT > 0) {
				//元素为普通符号 且要删除的元素个数不为0 说明该元素需要删除
				// 删除该元素，元素索引值减1
				skipT--, j--;
			}
			else {
				// 元素为普通符号 且要删除的元素个数为0 说明该元素不需要删除
				// 跳出循环 当前索引j指向不需要删除的元素
				break;
			}
		}
		if (i >= 0 && j >= 0) {
			// ij索引指向元素值
			if (s[i] != t[j]) {
				// 比较两个字符串中当前不需要删除的元素值
				return false;
			}
		}
		else {
			if (i >= 0 || j >= 0) {
				// 一个字符串已经遍历完成 一个字符串还未遍历完成
				// 这种情况下两个字符串肯定不相等
				return false;
			}
		}
		// 若两个字符串都未遍历完成 且当前未删除的元素相等 
		// 则将当前元素指向的索引值减1 重新开始寻找
		i--, j--;
	}
	// 如果为删减的元素全部都相等 返回true
	return true;
}


int main()
{
	string s = "a##c";
	string t = "#a#c";
	bool flag = backspaceCompare(s, t);
	cout << "最终的结果为：" << flag << endl;

	system("pause");

	return 0;
}
