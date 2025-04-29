# include <iostream>
using namespace std;
/*
for循环练习案例:
从1开始数到100，如果数字个位含有7，或数字十位含有7，或该数字是7的倍数
打印输出敲桌子，否则直接打印输出
*/
int main()
{
	int num = 0;
	int bit_num = 0;
	int ten_num = 0;
	for (num = 1; num < 100; num++)
	{
		bit_num = num % 10; // 个位
		ten_num = num / 10; // 十位
		if (bit_num == 7 || ten_num == 7 || num % 7 == 0)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << num << endl;
		}
	}
	system("pause");
	return 0;
}