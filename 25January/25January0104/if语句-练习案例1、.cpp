# include <iostream>
using namespace std;
/*
������ֻС��ABC�����أ��ж�����˭����
��ֻС�����ز����
*/
int main()
{
	float A = 0;
	float B = 0;
	float C = 0;
	cout << "����С��A������" << endl;
	cin >> A;
	cout << "����С��B������" << endl;
	cin >> B;
	cout << "����С��C������" << endl;
	cin >> C;
	if (A > B)
	{
		if (A > C)
		{
			cout << "С��A����" << endl;
		}
		else
		{
			cout << "С��C����" << endl;
		}
	}
	else
	{
		if (B > C)
		{
			cout << "С��B����" << endl;
		}
		else
		{
			cout << "С��C����" << endl;
		}
	}
	system("pause");
	return 0;
}