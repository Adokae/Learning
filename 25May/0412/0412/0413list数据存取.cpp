# include <iostream>
using namespace std;
#include <list>
/*
list���ݴ�ȡ��

������
1 front();���ص�һ��Ԫ��
2 back(); �������һ��Ԫ��
*/

void test1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	// ��������[]��ʽ�������� 
	// �޷���at��ʽ����
	//ԭ������list������������ �������������Կռ�洢���� ��������֧���������

	cout << "��λԪ�أ�" << L1.front() << endl;
	cout << "β��Ԫ��:" << L1.back() << endl;

	// ��������֧���������
	list<int>::iterator it = L1.begin();
	it++;// ֻ��һ�������� ˫�����
	cout << *(it++) << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}
