# include <iostream>
using namespace std;
/*
输入三只小猪ABC的体重，判断其中谁最重
三只小猪体重不相等
*/
int main()
{
	float A = 0;
	float B = 0;
	float C = 0;
	cout << "输入小猪A的体重" << endl;
	cin >> A;
	cout << "输入小猪B的体重" << endl;
	cin >> B;
	cout << "输入小猪C的体重" << endl;
	cin >> C;
	if (A > B)
	{
		if (A > C)
		{
			cout << "小猪A最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}
	else
	{
		if (B > C)
		{
			cout << "小猪B最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}
	system("pause");
	return 0;
}