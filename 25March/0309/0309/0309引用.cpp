# include <iostream>
using namespace std;

/*
���ã�
���ã������������
�﷨�� ��������(��ԭ��һ��) &���� = ԭ��
*/
int main()
{
	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	system("pause");

	return 0;
}
