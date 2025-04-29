# include <iostream>
using namespace std;
/*
二维数组名用途：
1 查看所占用内存空间大小
2 可查看二维数组首地址
*/ 

int main()
{
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	// 二维数组所占用内存大小
	// 一个int占用4bit，6*4=24
	cout << "二维数组所占用内存空间大小" << sizeof(arr) << endl;
	cout << "二维数组第一行所占用内存空间大小" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素所占用内存空间大小" << sizeof(arr[0][0]) << endl;
	cout << "二维数组行数" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	
	// 二维数组首地址
	cout << "二维数组首地址" << (int)arr << endl;
	cout << "二维数组第一行首地址" << (int)arr[0] << endl;
	cout << "二维数组第二行首地址" << (int)arr[1] << endl;
	cout << "二维数组第一个元素首地址" << (int)&arr[0][0] << endl;
	system("pause");

	return 0;
}
