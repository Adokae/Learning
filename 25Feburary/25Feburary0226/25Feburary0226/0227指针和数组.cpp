# include <iostream>
using namespace std;

/*
ָ������飺����ָ�������������е�Ԫ��
*/
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// ����ָ��
	int* p = arr; // arr����������׵�ַ

	cout << "����ָ����ʵ�һ��Ԫ�أ�" << *p << endl;
	p++; // ��ָ������ĸ��ֽ� ��������һ��int������ָ��
	cout << "����ָ����ʵڶ���Ԫ�أ�" << *p << endl;

	cout << "����ָ���������" << endl;
	int* p2 = arr;
	for (int i = 0; i<10; i++)
	{
		cout << *p2 << endl;
		p2++;

	}

	system("pause");

	return 0;
}
