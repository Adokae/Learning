# include <iostream>
using namespace std;

/*
�������ɳ���Ա�����ͷţ�������Ա���ͷţ��������ʱ�ɲ���ϵͳ����
��cpp����Ҫ����new�ڶ��������ڴ�
*/

int* func()
{
	// ����new�ؼ��� �����ݿ��ٵ�����
	// ָ�� ������Ҳ�Ǿֲ����� ����ջ�� ָ�뱣������ݷ��ڶ���
	int* p = new int(10);
	return p;
}
int main()
{
	// �ڶ�����������
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	system("pause");

	return 0;
}
