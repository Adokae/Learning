# include <iostream>
using namespace std;
const double PI = 3.14;
/*
C++��������������ԣ���װ���̳С���̬

C++����������Զ��󣬶����������Ժ���Ϊ

�ࣺ������ͬ���ʵĶ���

��װ���壺
1 �����Ժ���Ϊ��Ϊһ�����壬���������е�����
2 �����Ժ���Ϊ����Ȩ�޿���
*/

// ���һ��Բ�࣬��Բ���ܳ�
// class��ʾ���һ���࣬��������������
class Circle
{
	// ����Ȩ��
	// ����Ȩ��
public:
	// ���ԣ��뾶
	int m_r;
	// ��Ϊ����ȡԲ���ܳ�
	double calculateZC()
	{
		return 2 * PI * m_r;
	}

};
int main()
{
	// ͨ��Բ�ഴ���������
	// ʵ����-ͨ��һ���ഴ��һ������
	Circle cl;
	// ��Բ��������Խ��и�ֵ

	cl.m_r = 10;

	cout << "Բ���ܳ�" << cl.calculateZC() << endl;
	system("pause");

	return 0;
}
