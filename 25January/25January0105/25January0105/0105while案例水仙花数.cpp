# include <iostream>
using namespace std;

/*
��ϰ������ˮ�ɻ���
ˮ�ɻ���ָһ����λ��������ÿ��λ�ϵ����ֵ�3��ڤ֮�͵���������
��do...while������������λ���е�ˮ�ɻ���
*/
int main()
{
	int num = 100;
	int hundred_num = 0; //��λ
	int ten_num = 0;// ʮλ
	int bit = 0; // ��λ
	do
	{
		hundred_num = num / 100;
		ten_num = (num - (hundred_num*100))/10;
		bit = num - (hundred_num * 100) - ten_num * 10;
		if (num == (pow(hundred_num, 3) + pow(ten_num, 3) + pow(bit, 3)))
		{
			cout << num <<endl;
		}
		num++;
	} while (num < 1000);
	system("pause");
	return 0;
}