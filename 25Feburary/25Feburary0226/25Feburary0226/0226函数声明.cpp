# include <iostream>
using namespace std;


/*
�������� ��ǰ���߱����������Ĵ��ڣ��������ú���������
ͨ�����������������Խ�������������������
������������д��Σ���ʱ��������ֻ����һ��
*/

// ʵ�����������ıȽϣ����ؽϴ�ֵ
int max(int a, int b);

int main()
{

	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;
	system("pause");

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;

}