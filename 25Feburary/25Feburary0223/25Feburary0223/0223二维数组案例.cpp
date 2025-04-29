# include <iostream>
# include <string>
using namespace std;
// 二维数组应用案例:输出三名同学的总成绩
int main()
{
	int score[3][3] = {
		{100, 100, 100},
		{90,50,100},
		{60,70,80}
	};
	string names[3] = { "张三","李四","王五" };
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += score[i][j];
		}
		cout <<names[i] << "的成绩是" << sum << endl;
	}
	system("pause");

	return 0;
}