# include <iostream>
using namespace std;
/*
指针 数组和函数
封装一个函数，利用冒泡排序，实现对整型数组的升序排序
*/

void bubblesort(int * arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j ] = arr[j+ 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void prinfArray(int* arr, int len)
{

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	int arr[10] = { 10, 5,2,6,1,9,7,4,8,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, len);
	prinfArray(arr, len);

	system("pause");

	return 0;
}
