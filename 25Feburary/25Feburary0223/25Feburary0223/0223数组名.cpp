#include <iostream>
using namespace std;

/*
������Ϊ�����������޸�

��������;��
1 ͳ�������������ڴ��еĳ��ȣ�sizeof(������)
sizeof(arr[0])-������Ԫ�صĳ���
2 ��ȡ�������ڴ��е��׵�ַ
��ӡ���arr
*/
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	// ��������;1��ͳ��������ռ�ڴ�ռ�Ĵ�С
	cout << "��������ռ���ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	// ���40��ÿ��int������ռ�ڴ�ռ�Ϊ4��10��Ԫ��ռ40
	cout << "�����е���Ԫ����ռ���ڴ�ռ��С��" << sizeof(arr[0]) << endl;
	cout << "������Ԫ�ظ���" << sizeof(arr) / sizeof(arr[0]) << endl;

	// ��;2 �鿴�����׵�ַ
	cout << arr << endl; // ���Ϊ16����
	cout << (int)arr << endl; // �������16������ת��Ϊ10����
	cout << (int)&arr[0] << endl; // ��������Ԫ�صĵ�ַ
	cout << (int)&arr[1] << endl;


	system("pause");
	return 0;
}
