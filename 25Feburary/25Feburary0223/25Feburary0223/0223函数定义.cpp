# include <iostream>
using namespace std;

/*
��������һ��������²��裺
1 ����ֵ����
2 ������
3 ��������
4 ���������
5 return ���ʽ

�﷨��
����ֵ���� ������(�����б�)
{
	������
	return���ʽ
}

�������ã� ��������(����)
*/

// ʵ�ּӷ�����
// ��������ʱ��num1, num2��Ϊ�βΣ�ֻ����ʽ�ϵĲ���
int add(int num1,int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main()
{
	int num1 = 2;
	int num2 = 6;
	// �˴���num1��num2Ϊʵ��
	cout << add(num1, num2) << endl;
	system("pause");

	return 0;
}