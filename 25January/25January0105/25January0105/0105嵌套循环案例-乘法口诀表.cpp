# include <iostream>
using namespace std;
/*
ʹ��Ƕ��ѭ������ӡ����žų˷��ھ���
*/
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %d", j, i, i * j);
			printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}