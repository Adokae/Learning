# include <iostream>
using namespace std;
/*
C++��struct��classΨһ�����������Ĭ�ϵķ���Ȩ�޲�ͬ
����
struct:Ĭ��Ȩ��Ϊ����
class:Ĭ��Ȩ��Ϊ˽��
*/
class C1
{
	int m_A; // Ĭ��˽��
};

struct C2
{
	int m_B;
};

int main()
{
	C1 c1;
	// classĬ��˽�� ���´��뱨��
	//c1.m_A = 100;
	C2 c2;
	c2.m_B = 100;
	cout << c2.m_B << endl;
	system("pause");

	return 0;
}
