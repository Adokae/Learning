# include <iostream>
using namespace std;

/* 多行if语句
若满足条件，执行一个条件
若不满足条件，执行另一个条件
*/
int main() 
{
	// 多行if语句
	int score = 0;
	cout << "输入分数：" << endl;
	cin >> score;
	cout << "输出分数：" << score << endl;
	if (score > 600)
	{
		cout << "分数大于600" << endl;
	}
	else
	{
		cout << "分数不大于600" << endl;
	}
	system("pause");
	return 0;

}
