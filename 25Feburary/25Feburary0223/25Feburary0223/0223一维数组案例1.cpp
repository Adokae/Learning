#include <iostream>
using namespace std;

/*
一维数组案例1
在一个数组中记录五只小猪的体重，找出并打印最重的小猪体重
*/
int main()
{
	int arr[5] = {300,350,200,400,250};
	int max = arr[0];
	for (int i = 1; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("最重的小猪体重为：%d\n", max);

	system("pause");

	return 0;
}
