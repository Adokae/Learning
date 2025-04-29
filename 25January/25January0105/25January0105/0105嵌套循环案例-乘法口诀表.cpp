# include <iostream>
using namespace std;
/*
使用嵌套循环，打印输出九九乘法口诀表
*/
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %d", j, i, i * j);
			printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}