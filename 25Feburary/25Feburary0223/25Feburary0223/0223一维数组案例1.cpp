#include <iostream>
using namespace std;

/*
һά���鰸��1
��һ�������м�¼��ֻС������أ��ҳ�����ӡ���ص�С������
*/
int main()
{
	int arr[5] = {300,350,200,400,250};
	int max = arr[0];
	for (int i = 1; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("���ص�С������Ϊ��%d\n", max);

	system("pause");

	return 0;
}
