# include <iostream>
using namespace std;
/*
switch语句-执行多条件分支语句
语法结构：
switch(表达式)
{
  case 结果1(表达式的结果)：执行语句；break;
  ...
  default:执行语句；break;
}

if与switch区别：
switch:判断是只能是整型或字符型，不能是一个区间,结构清晰，执行效率高
*/
int main()
{
	// switch语句
	cout << "给电影评分，分数范围在0到10之间，输入分数：" << endl;
	int score = 0;
	cin >> score;
	switch (score)
	{
	case 10:
		cout << "经典电影" << endl;
		break;
	case 7:
		cout << "非常好" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}
	system("pause");
	return 0;
}
