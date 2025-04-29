# include <iostream>
using namespace std;
/*
for循环语句
满足循环条件，执行循环语句
语法：for(起始表达式；条件表达式；末尾循环体){循环语句;}
*/
int main()
{
	// for循环输出0到9之间的数
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}