# include <iostream>
using namespace std;
/*
һά���鰸��2��
����һ��5��Ԫ�ص����飬����Ԫ������
*/
int main()
{
	int arr[5] = { 1,3,2,5,4 };
	for (int i = 0; i < 2; i++)
	{
		int num = arr[i];
	    arr[i] = arr[5 - i - 1];
		arr[5 - i - 1] = num;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");

	return 0;

}