# include <iostream>
using namespace std;

/*
�����β��б��������ռλ������������ռλ�����ú����Ǳ������λ��
�﷨�� ����ֵ���� ������(��������) {}
*/

// ռλ����
// ռλ����������Ĭ�ϲ���
void func(int a, int = 10)
{
	// �ڶ���int��ʾռλ
	cout << "this is a function " << endl;
}
int main()
{
	func(10, 10); // ���뺯���Ķ�Ӧ��ռλ�����޷�ʹ��
	system("pause");

	return 0;
}
