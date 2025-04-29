# include <iostream>
using namespace std;
/*
多条件if语句
判断是否满足条件1 满足则执行条件1
不满足在判断其是否满足条件2 满足则执行条件2 以此类推
直到都不满足条件 在执行最后的条件
*/
int main()
{   
	int score = 0;
	cout << "输入分数：" << endl;
	cin >> score;
	cout << "输出分数" << endl;
	if (score > 600)
	{
		cout << "分数大于600" << endl;
	}
	else if (score > 500)
	{
		cout << "分数在500到600之间 " << endl;
	}
	else if (score > 400)
	{
		cout << "分数在400到500之间" << endl;
	}
	else
	{
		cout << "分数在400分以下" << endl;
	}
	system("pause");
	return 0;
}