# include <iostream>
using namespace std;
/*
跳转语句：用于跳出选择结构或循环结构
break语句：
1）出现在switch条件语句中，作用是终止case并跳出switch
2）出现在循环语句中，作用是跳出当前的循环语句
3）出现在嵌套循环中，跳出最劲的内层循环语句
*/
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
		if (i == 5)
		{
			break;
		}
	}
	system("pause");
	return 0;

}