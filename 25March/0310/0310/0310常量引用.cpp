# include <iostream>
using namespace std;

/*
����������Ҫ���������βΣ���ֹ�����
�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��
*/

void Print(const int& val)
{
	// ��const��ֹ�ں������ڲ��޸�����
	cout << "val=" << val << endl;
}

int main()
{
	int a = 10;
	int& ref = a;// ���ñ�����һ��Ϸ����ڴ�ռ䣬����ֱ��������
	// ����ʾ��
	//int& ref = 10;

	// ��ȷʾ��
	//��const ����������������Ϊ 
	//int temp = 10; const int &ref = temp;
	// ������const���Ϊֻ�� �������޸�
	//const int& ref2 = 10;
	Print(a);
	system("pause");

	return 0;
}
