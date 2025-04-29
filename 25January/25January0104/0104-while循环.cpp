# include <iostream>
using namespace std;

/* 
while循环结构 满足循环条件，执行循环语句
一定要避免死循环
*/
int main()
{
	// 打印0-9这十个数字
	int num = 0;
	while (num < 10)
	{
		cout << num << endl;
		num++;
	}
	system("pause");
	return 0;
}