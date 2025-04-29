# include <iostream>
using namespace std;
/*
在嵌套循环体中在嵌套一层循环
*/
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}