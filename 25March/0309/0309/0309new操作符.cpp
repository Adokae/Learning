# include <iostream>
using namespace std;

/*
new�������������ڶ�����������
�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ��ͷ����ò�����delete
�﷨�� new ��������
����new���������ݣ��᷵�ظ����ݶ�Ӧ�����͵�ָ��
*/

int* func()
{
	// �ڶ���������������
	int* p = new int(10);
	return p;
}

void test1()
{
	// ���������ɳ���Ա����
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	// �ͷŶ������� ���ùؼ���delete
	delete p;
	// cout << *p << endl; // �ڴ��ѱ��ͷţ��ٴη��ʣ�����
}

// �ڶ�����������
void test2()
{
	// �ڶ�������10����������
	int * arr = new int[10];//[]��ʾ��������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	// �ͷŶ������� �ͷ�����Ҫ��[]
	delete[] arr;
}

int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}
