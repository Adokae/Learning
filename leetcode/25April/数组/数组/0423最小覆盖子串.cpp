#include <iostream>
using namespace std;
#include <unordered_map>
// 返回s中涵盖t所有字符的最小子串
class Solution {
public:
	unordered_map <char, int> ori, cnt;
	// 用哈希表存储字符串中各字符出现的此处 题目要求涵盖t即可 不要求字符串出现次序
	// ori记录字符串t cnt记录字符串s

	bool check() {
		// 让编译器自动推断p的类型 p是pair队组类型
		// 判断滑动窗口cnt中字符是否包含t中所有字符的要求
		for (const auto& p : ori) {
			if (cnt[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto& c:t) {
			++ori[c];
		}// 遍历t中字符串 统计t中各字符出现次数
		int l = 0, r = -1;// 窗口左右指针
		int len = INT_MAX, ansL = -1, ansR = -1;// 记录最小覆盖子串的起始和结束位置
		while (r<int(s.size())) {
			// 先对r加1 在判断s[r]是否等于ori.end() 滑动右指针 使其覆盖t中所有元素
			if (ori.find(s[++r]) != ori.end()){
				++cnt[s[r]];// 窗口中存储的也只有ori中的字符
			}
			// 当前滑动窗口中包含子串中的字符 且右指针大于左指针
			while (check() && l <= r) {
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}// 当前窗口指针小于之前统计的窗口指针 更新子串长度和最小子串起始位置
				if (ori.find(s[l]) != ori.end()) {
					--cnt[s[l]];
				}//左指针指向字符存在于ori中 该字符在窗口中数量减1 因为要考虑cnt本身存储的内容
				++l;// 移动左指针
			}
		}
		return ansL == -1 ? string() : s.substr(ansL, len);
	}
};


int main() {
	string s = "ABOBECODEBANC";
	string t = "ABC";
	Solution so;
	string ret = so.minWindow(s, t);
	cout << "输出结果是：" << ret << endl;

	system("pause");
	return 0;
}