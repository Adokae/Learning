# include <iostream>
using namespace std;
/*
��Ŀ�����
���ʽ1�����ʽ2�����ʽ3
�����ʽ1Ϊ�棬ִ�б��ʽ2
�����ʽ1Ϊ�٣�ִ�б��ʽ3
*/
int main()
{
	//������������ a b c
	// ��a��b���Ƚ� ���������ֵ��ֵ������c
	system("pause");
	int a = 10;
	int b = 20;
	int c = 0;
	a > b ? c = a : c = b;
	cout << "���a��b֮������ֵ" << c << endl;
	return 0;
}