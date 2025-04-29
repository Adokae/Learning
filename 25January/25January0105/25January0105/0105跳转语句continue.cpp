# include <iostream>
using namespace std;
/*
continue语句：在循环语句中，跳过本次循环中余下尚未执行的语句，
继续执行下一次循环
可以筛选条件，执行到此就不再向下执行，执行下一次循环
*/
int main()
{
	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		printf("%d\n", i);
	}
	system("pause");
	return 0;

}