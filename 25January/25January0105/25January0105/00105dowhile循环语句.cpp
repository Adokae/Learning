# include <iostream>
using namespace std;

/*
do...while循环语句
满足循环条件，就执行循环语句
该语句会先执行一次循环语句，在判断循环条件
do {循环语句} while(循环条件);
*/
int main()
{
	// do...while循环语句
	// 在循环中输出0到9这十个数字
	int num = 0;
	do
	{
		cout << num << endl;
		num++;
	} while (num < 10);
	system("pause");
	return 0;
}