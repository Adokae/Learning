# include <iostream>
using namespace std;
/*
������if���
�ж��Ƿ���������1 ������ִ������1
���������ж����Ƿ���������2 ������ִ������2 �Դ�����
ֱ�������������� ��ִ����������
*/
int main()
{   
	int score = 0;
	cout << "���������" << endl;
	cin >> score;
	cout << "�������" << endl;
	if (score > 600)
	{
		cout << "��������600" << endl;
	}
	else if (score > 500)
	{
		cout << "������500��600֮�� " << endl;
	}
	else if (score > 400)
	{
		cout << "������400��500֮��" << endl;
	}
	else
	{
		cout << "������400������" << endl;
	}
	system("pause");
	return 0;
}