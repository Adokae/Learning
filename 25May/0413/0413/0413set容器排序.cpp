# include <iostream>
using namespace std;
#include <set>
/*
set����Ĭ���������Ϊ��С�������÷º������ı��������

*/
class myCompare
{
public:
	// ��һ��С���ű�ʾҪ���صķ��� �ڶ���С���ű�ʾ�����б�

	// ��Ҫ��const ����const ��������ʱ �º�����ͼ�޸�����thisָ�� Υ����const_iterator��Լ��
	// ���±������ ���Ҳ���constʱҲ������
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};



void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// Ĭ����������С���� �ı�������� �Ӵ�С
	set<int, myCompare>s2;

	s2.insert(10);
	s2.insert(40);
	s2.insert(30);
	s2.insert(20);
	for (set<int, myCompare>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


int main()
{
	test1();
	system("pause");

	return 0;
}
