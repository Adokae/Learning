# include <iostream>
using namespace std;

/*
练习案例：水仙花数
水仙花是指一个三位数，它的每个位上的数字的3次冥之和等于它本身
用do...while语句求出所有三位数中的水仙花数
*/
int main()
{
	int num = 100;
	int hundred_num = 0; //百位
	int ten_num = 0;// 十位
	int bit = 0; // 个位
	do
	{
		hundred_num = num / 100;
		ten_num = (num - (hundred_num*100))/10;
		bit = num - (hundred_num * 100) - ten_num * 10;
		if (num == (pow(hundred_num, 3) + pow(ten_num, 3) + pow(bit, 3)))
		{
			cout << num <<endl;
		}
		num++;
	} while (num < 1000);
	system("pause");
	return 0;
}