# include <iostream>
using namespace std;
#include <vector>

int removeDuplicates(vector<int>& nums)
{
	
	// 暴力解法 比较当前元素与下一个元素值 若相等 覆盖当前元素
	// int len = nums.size();
	//for (int i = 0; i < len - 1; i++) {
	//	if (nums[i] == nums[i + 1]) {
	//		for (int j = i; j < len - 1; j++) {
	//			nums[j] = nums[j + 1];
	//		}
	//		len--;
	//		i--;// 覆盖后需要重新比较当前元素与下一个元素的值
	//	}
	//}
	//return len;

	// 双指针 判断要找的元素的不同位置 如果nums[i]=nums[j]，说明i到j间所有元素都相等
	// 我们要找的是不同的元素 通过遍历数组 将不相同的元素去覆盖慢指针所对应的元素
	int slowIndex = 1;
	for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
		if (nums[slowIndex-1] != nums[fastIndex]) {
			nums[slowIndex] = nums[fastIndex];
			slowIndex++;
		}
	}
	return slowIndex;
}


int main()
{
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4};
	int elem = removeDuplicates(nums);
	cout << "最终的结果为：" << elem << endl;

	system("pause");

	return 0;
}
