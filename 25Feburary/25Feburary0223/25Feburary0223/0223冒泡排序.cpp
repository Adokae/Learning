# include <iostream>
using namespace std;

/*
ð������
�Ƚ���������Ԫ�أ�����һ���ȵڶ������򽻻�����λ��
һ�������ҵ�һ�����ֵ����һ�ֱ���һ���ٱȽ�һ����
*/
int main() 
{
	// ����ð������ʵ����������
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	int ele_num = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	// ����
	// ����ʾ�ܹ�����������������������Ԫ�ظ���-1
	for (int i = 0; i < 9 - 1; i++)
	{
		// �ڲ㽻��-����Ԫ�ؼ�Ľ���
		// ��������=Ԫ�ظ���-��ǰ����-1
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (k = 0; k < 9; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;

	system("pause");

	return 0;

}
