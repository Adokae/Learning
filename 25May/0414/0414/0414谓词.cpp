# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
ν�ʸ��
1 ����bool���͵ķº�����Ϊν��
2 ��operator()����һ����������ΪһԪν��
3 ��operator()����������������Ϊ��Ԫν��

*/
// һԪν��
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ���������д���5������
	// find_if�е�GreaterFive()Ϊ������������
	vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5������Ϊ��" << *it << endl;
	}
}
int main()
{
	test1();
	system("pause");

	return 0;
}
