# include <iostream>
using namespace std;
/*
三种程序运行结构：顺序结构、选择结构、循环结构
顺序结构：程序按顺序执行，不发生跳转
选择结构：根据条件是否满足，执行相应功能
循环结构：根据条件是否满足，循环多次执行某段代码
*/
/*
选择结构：
1）if语句
三种形式：单行格式、多行格式、多条件

*/

int main()
{
	// 选择结构 if语句-单行格式
	int score = 0;
	cout << "请输入分数：" << endl;
	cin >> score;
	cout << "输出分数" << score << endl;
	// 注意事项：if条件后不要加分号，加分号，不管是否满足条件
	// 一定执行if后的条件
	if (score > 600)
	{
		cout << "输入分数大于600" << endl;
	}
	system("pause");
	return 0;
}
