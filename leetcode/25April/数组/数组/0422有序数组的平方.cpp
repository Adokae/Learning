# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int s)
{
	cout << s << " ";
}

vector<int> sortedSquares(vector<int>& nums)
{
	int n = nums.size();
	vector<int> new_nums;// 存最终的值
	// 先找数组中大于0与小于0元素的索引值
	int lesszeroIndex = -1;
	for (int i = 0; i < n; i++) {
		if (nums[i] < 0) {
			lesszeroIndex = i;
		}
	}
	// lesszeronIndex = -1 说明数组中元素全大于0 此时不需要排序 将原数组元素
	// 平方形成新数组即可
	if (lesszeroIndex == -1) {
		for (int j = 0; j < n; j++) {
			new_nums.push_back(nums[j] * nums[j]);
		}
		return new_nums;
	}
	// lesszeronIndex = n-1 说明数组中元素全小于0 此时进行逆序排列
	else if (lesszeroIndex == n - 1) {
		for (int j = n - 1; j >= 0; j--) {
			new_nums.push_back(nums[j] * nums[j]);
		}
	}
	// 不满足上面两种情况 说明数组中元素有大于0有小于0的元素 此时进行归并排序
	else {
		vector<int>new_num1;// 存小于0的元素的平方值
		vector<int>new_num2;// 存大于0的元素的平方值
		for (int k1 = lesszeroIndex; k1 >= 0; k1--) {
			new_num1.push_back(nums[k1] * nums[k1]);
		}
		for (int k = lesszeroIndex+1; k < n; k++) {
				new_num2.push_back(nums[k] * nums[k]);
		}
		int left_i = 0, right_i = 0;
		while (left_i < new_num1.size() && right_i < new_num2.size()) {
			if (new_num1[left_i] <= new_num2[right_i]) {
				new_nums.push_back(new_num1[left_i]);
				left_i++;
			}
			else {
				new_nums.push_back(new_num2[right_i]);
				right_i++;
			}
		}
		while (left_i < new_num1.size()) {
			new_nums.push_back(new_num1[left_i]);
			left_i++;
		}
		while (right_i < new_num2.size()) {
			new_nums.push_back(new_num2[right_i]);
			right_i++;
		}
	}
	return new_nums;
}


int main()
{
	vector<int> nums = {-10,-5,-3,-2,0};
	vector<int>new_nums = sortedSquares(nums);
	for_each(new_nums.begin(), new_nums.end(), print);
	cout << endl;
	system("pause");

	return 0;
}
