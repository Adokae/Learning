# include <iostream>
using namespace std;
# include <ctime>
/*
whileѭ����ϰ������������
ϵͳ�������һ��1��100������֣����������в²⣬
���´���ʾ������ֹ�����С
���¶ԣ���ϲ���ʤ�������˳���Ϸ
*/
int main()
{
	// ����������������ֹÿ�����������һ��
	srand((unsigned int)time(NULL));

	int num = rand() % 100 + 1; // ����1��100֮��������
	int guess_num = 0;
	cout << "�����������²�����֣�" << endl;
	cin >> guess_num;
	while (guess_num != num)
	{
		if (guess_num > num)
		{
			cout << "������������ֹ�������������" << endl;
			cin >> guess_num;
		}
		else
		{
			cout << "������������ֹ�С������������" << endl;
			cin >> guess_num;
		}
	}
	cout << "�²�ɹ�" << endl;
	system("pause");
	return 0;
}
