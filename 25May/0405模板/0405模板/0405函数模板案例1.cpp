# include <iostream>
using namespace std;
/*
����ģ�尸����
���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������ͽ�������
������򰴴Ӵ�С�ţ������㷨Ϊѡ������
�ֱ�ʹ��char��int�������ͽ��в���
*/

template<typename T>

void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			T temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;

		}
	}
}

void test1()
{
	//����char����
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	mySort(charArr, num);
	cout << charArr << endl;

}

void test2()
{
	//����������������
	int intArr[] = {7, 5, 1, 3, 9, 100, 10};
	int num = sizeof(intArr) / sizeof(intArr[0]);
	mySort(intArr, num);
	for (int i = 0; i < num; i++)
	{
		cout << intArr[i] << " ";
	}
	cout << " " << endl;
}
int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}
