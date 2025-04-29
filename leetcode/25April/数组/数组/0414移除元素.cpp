# include <iostream>
using namespace std;
#include <vector>

int removeElement(vector<int>& nums, int val)
{
	// 暴力解法;遍历，找到等于val的值，就用后面的数组对该值进行覆盖
	//int elem = nums.size();
	//for (int i = 0; i < elem; i++)
	//{
	//	if (nums[i] == val)
	//	{
	//		// 注意 设置j=i+1时 此处为j < elem 则第一次遍历时最大的j为7 
	//		// 因此需要num[j-1]=nums[j],不会超出索引限制
	//		// 若设置j=i 需要nums[j]=nums[j+1]，则跳出循环的条件为j < elem-1
	//		for (int j = i; j < elem - 1; j++)
	//		{
	//			nums[j] = nums[j + 1];
	//		}
	//		i--;// 需要重新覆盖后位置为i的值 故需要先减1
	//		elem--;// 覆盖 整体大小也小于1
	//	}
	//}

	//for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	//return elem;


	// 快慢指针解决  快指针用于在数组中寻找满足要求的元素 即不含有目标元素的的数组
	// 慢指针：指向新数组中的下标的位置(满足最终要求的数组)
	int slowIndex = 0;
	for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
	{
		if (nums[fastIndex] != val)
		{
			nums[slowIndex] = nums[fastIndex]; // 快指针指向的元素不等于目标元素时
			slowIndex++;
		}
	}
	return slowIndex;

}


int main()
{
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int val;
	cout << "输入目标值" << endl;
	cin >> val;
	int elem = removeElement(nums, val);
	cout << "最终的结果为：" << elem << endl;

	system("pause");

	return 0;
}
