# include <iostream>
using namespace std;

/*
ȫ�������洢ȫ�ֱ�������̬������������ȫ�ֳ�����

ȫ�ֱ����;ֲ���������һ������
��̬������ȫ�ֱ�����һ������ 
�ַ��������뾲̬������ȫ�ֱ����ܽ�

�ֲ��������ֲ�������һ�����ڣ�����ȫ�����ڣ�

ȫ�����ڣ�ȫ�ֱ�������̬�������ַ���������ȫ�ֳ���
*/

// �������ⲿ Ϊȫ�ֱ���
int g_a = 10;
int g_b = 10;
// const���ε�ȫ�ֱ��� ȫ�ֳ���
const int c_g_c = 10;
const int c_g_d = 10;
int main()
{

	// �������ڲ�������Ϊ�ֲ�����
	int a = 10;
	int b = 10;
	cout << "a���ڴ��ַΪ��" << (int)&a << endl;
	cout << "b���ڴ��ַΪ��" << (int)&b << endl;

	cout << "ȫ�ֱ���g_a���ڴ��ַΪ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b���ڴ��ַΪ��" << (int)&g_b << endl;

	// ��̬����
	// ����ͨ����ǰ���static ���ھ�̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a���ڴ��ַΪ��" << (int)&s_a << endl;
	cout << "��̬����s_b���ڴ��ַΪ��" << (int)&s_b << endl;

	// ����
	// �ַ�������
	cout << "�ַ��������ĵ�ַΪ��" << (int)&"hello world" << endl;
	// const���εı���
	// const���ε�ȫ�ֱ��� const���εľֲ�����

	cout << "ȫ�ֳ��� c_g_c�ĵ�ַΪ��" << (int)&c_g_c<< endl;
	cout << "ȫ�ֳ��� c_g_d�ĵ�ַΪ��" << (int)&c_g_d << endl;

	// const���εľֲ�����
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "�ֲ����� c_l_a�ĵ�ַΪ��" << (int)&c_l_a << endl;
	cout << "�ֲ����� c_l_b�ĵ�ַΪ��" << (int)&c_l_b << endl;
	system("pause");

	return 0;
}
