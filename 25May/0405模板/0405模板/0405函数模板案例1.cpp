# include <iostream>
using namespace std;
/*
函数模板案例：
利用函数模板封装一个排序的函数，可以对不同数据类型进行排序
排序规则按从大到小排，排序算法为选择排序
分别使用char和int数据类型进行测试
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
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	mySort(charArr, num);
	cout << charArr << endl;

}

void test2()
{
	//测试整数类型数据
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
