#include <iostream>
using namespace std;
#include <climits>// 头文件中的常量
#include <vector>
/*
209-长度最小的子数组
思路：1 暴力 遍历数组中所有满足条件的子数组 从中寻找长度最小的子数组
1 双指针 滑动窗口 先固定窗口终止位置 移动起始位置窗口寻找最短距离
如果窗口中数组元素和小于最短距离 移动窗口终止位置

*/

int minSubArrayLen(int target, vector<int>& nums) {
	// 1 暴力解法
	/*int result = INT_MAX;
	int sum;
	int len = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum = 0;
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			if (sum >= target) {
				len = j - i + 1;
				result = result < len ? result : len;
				break;
			}
		}
	}
	return result == -1 ? 0 : result;*/

	// 2 滑动窗口
	int i = 0;// 起始位置
	int sum = 0;
	int len = 0;
	int result = INT_MAX; // 最终结果
	// j表示终止位置
	for (int j = 0; j < nums.size(); j++) {
		sum += nums[j];
		while (sum >= target) {
			len = j - i + 1;
			result = result < len ? result : len;
			sum -= nums[i];
			i++;
		}
	}
	return result == INT_MAX?0:result;
}



int main() {
	vector<int> nums = { 2,3,1,2,4,3 };
	int target = 7;
	/*cout << "输入正整数target:" << endl;
	cin >> target;*/
	int result = minSubArrayLen(target, nums);
	cout << "result = " << result << endl;

	system("pause");
	return 0;
}