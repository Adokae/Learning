# include <iostream>
using namespace std;
/*
��ά��������;��
1 �鿴��ռ���ڴ�ռ��С
2 �ɲ鿴��ά�����׵�ַ
*/ 

int main()
{
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	// ��ά������ռ���ڴ��С
	// һ��intռ��4bit��6*4=24
	cout << "��ά������ռ���ڴ�ռ��С" << sizeof(arr) << endl;
	cout << "��ά�����һ����ռ���ڴ�ռ��С" << sizeof(arr[0]) << endl;
	cout << "��ά�����һ��Ԫ����ռ���ڴ�ռ��С" << sizeof(arr[0][0]) << endl;
	cout << "��ά��������" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά��������" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	
	// ��ά�����׵�ַ
	cout << "��ά�����׵�ַ" << (int)arr << endl;
	cout << "��ά�����һ���׵�ַ" << (int)arr[0] << endl;
	cout << "��ά����ڶ����׵�ַ" << (int)arr[1] << endl;
	cout << "��ά�����һ��Ԫ���׵�ַ" << (int)&arr[0][0] << endl;
	system("pause");

	return 0;
}
