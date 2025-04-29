#include <iostream>
using namespace std;

/*
数组名为常量，不可修改

数组名用途：
1 统计整个数组在内存中的长度，sizeof(数组名)
sizeof(arr[0])-该数组元素的长度
2 获取数组在内存中的首地址
打印输出arr
*/
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	// 数组名用途1：统计数组所占内存空间的大小
	cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
	// 输出40，每个int变量所占内存空间为4，10个元素占40
	cout << "数组中单个元素所占用内存空间大小：" << sizeof(arr[0]) << endl;
	cout << "数组中元素个数" << sizeof(arr) / sizeof(arr[0]) << endl;

	// 用途2 查看数组首地址
	cout << arr << endl; // 输出为16进制
	cout << (int)arr << endl; // 将输出的16进制数转换为10进制
	cout << (int)&arr[0] << endl; // 数组中首元素的地址
	cout << (int)&arr[1] << endl;


	system("pause");
	return 0;
}
