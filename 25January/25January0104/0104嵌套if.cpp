# include <iostream>
using namespace std;
/* 
��if����У�Ƕ��if��䣬ʹ�����жϸ���ȷ
*/
int main()
{
	int score = 0;
	cout << "���������" << endl;
	cin >> score;
	cout << "�������Ϊ"<< score << endl;
	if (score > 600)
	{
		cout << "��������600С��700" << endl;
		if (score > 700)
		{
			cout << "��������700" << endl;
		}
		else if (score > 650 && score <= 700)
		{
			cout << "��������650С�ڵ���700" << endl;
		}
	}
	else
	{
		cout << "����С��600" << endl;
	}
	system("pause");

	return 0;
}