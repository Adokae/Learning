# include <iostream>
using namespace std;
/*
forѭ����ϰ����:
��1��ʼ����100��������ָ�λ����7��������ʮλ����7�����������7�ı���
��ӡ��������ӣ�����ֱ�Ӵ�ӡ���
*/
int main()
{
	int num = 0;
	int bit_num = 0;
	int ten_num = 0;
	for (num = 1; num < 100; num++)
	{
		bit_num = num % 10; // ��λ
		ten_num = num / 10; // ʮλ
		if (bit_num == 7 || ten_num == 7 || num % 7 == 0)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << num << endl;
		}
	}
	system("pause");
	return 0;
}