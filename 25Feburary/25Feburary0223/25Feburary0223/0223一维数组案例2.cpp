# include <iostream>
using namespace std;
/*
一维数组案例2：
声明一个5个元素的数组，将其元素逆序
*/
int main()
{
	int arr[5] = { 1,3,2,5,4 };
	for (int i = 0; i < 2; i++)
	{
		int num = arr[i];
	    arr[i] = arr[5 - i - 1];
		arr[5 - i - 1] = num;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");

	return 0;

}