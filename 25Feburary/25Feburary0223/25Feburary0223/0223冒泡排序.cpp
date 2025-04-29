# include <iostream>
using namespace std;

/*
冒泡排序：
比较两个相邻元素，若第一个比第二个大，则交换两者位置
一个轮数找到一个最大值，下一轮比上一轮少比较一个数
*/
int main() 
{
	// 利用冒泡排序实现升序排列
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	int ele_num = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	// 排序
	// 外层表示总共交换轮数，交换轮数等于元素个数-1
	for (int i = 0; i < 9 - 1; i++)
	{
		// 内层交换-两个元素间的交换
		// 交换次数=元素个数-当前轮数-1
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (k = 0; k < 9; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;

	system("pause");

	return 0;

}
