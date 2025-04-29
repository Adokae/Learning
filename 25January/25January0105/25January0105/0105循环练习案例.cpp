# include <iostream>
using namespace std;
# include <ctime>
/*
while循环练习案例：猜数字
系统随机生成一个1到100间的数字，玩家随机进行猜测，
若猜错，提示玩家数字过大或过小
若猜对，恭喜玩家胜利，并退出游戏
*/
int main()
{
	// 添加随机种子数，防止每次生成随机数一致
	srand((unsigned int)time(NULL));

	int num = rand() % 100 + 1; // 生成1到100之间的随机数
	int guess_num = 0;
	cout << "请输入你所猜测的数字：" << endl;
	cin >> guess_num;
	while (guess_num != num)
	{
		if (guess_num > num)
		{
			cout << "你所输入的数字过大，请重新输入" << endl;
			cin >> guess_num;
		}
		else
		{
			cout << "你所输入的数字过小，请重新输入" << endl;
			cin >> guess_num;
		}
	}
	cout << "猜测成功" << endl;
	system("pause");
	return 0;
}
