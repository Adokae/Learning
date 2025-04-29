# include <iostream>
using namespace std;
/* 
在if语句中，嵌套if语句，使条件判断更精确
*/
int main()
{
	int score = 0;
	cout << "输入分数：" << endl;
	cin >> score;
	cout << "输入分数为"<< score << endl;
	if (score > 600)
	{
		cout << "分数大于600小于700" << endl;
		if (score > 700)
		{
			cout << "分数大于700" << endl;
		}
		else if (score > 650 && score <= 700)
		{
			cout << "分数大于650小于等于700" << endl;
		}
	}
	else
	{
		cout << "分数小于600" << endl;
	}
	system("pause");

	return 0;
}