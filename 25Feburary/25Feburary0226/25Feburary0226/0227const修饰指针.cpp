# include <iostream>
using namespace std;

/*
const����ָ�����������������
1 const����ָ�� --����ָ��
�ص㣺 ָ���ָ������޸ģ���ָ��ָ���ֵ�����Ը�
2 const���γ��� --ָ�볣��
�ص㣺ָ���ָ�򲻿��Ըģ���ָ��ָ���ֵ�����޸�
3 const������ָ�� �����γ��� 
�ص㣺ָ���ָ���ָ��ָ���ֵ���������޸�
*/
int main()
{
	// 1 ����ָ��
	int a = 10;
	int b = 10;
	const int * p = &a;
	//*p = 20;  ����
	p = &b;

	// 2 ָ�볣��
	int* const p2 = &a;
	*p2 = 100;

	// 3 const������ָ�� �����γ���
	const int* const p3 = &a;
	// *p3 = 100; ����

	system("pause");

	return 0;
}