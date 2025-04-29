# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
transform��������������һ��������

������
transform(iterator beg1,iterator end1, iterator beg2, _func);
beg1 Դ������ʼ������
end1 Դ��������������
beg2 Ŀ��������ʼ������
_func ������������

*/
class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
};

class print1
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	// ��������������ǰ�����ڴ�ռ�
	vTarget.resize(v.size());

	transform(v.begin(), v.end(), vTarget.begin(), Transform());// ��ת�ƹ����п���һЩת������
	
	for_each(vTarget.begin(), vTarget.end(), print1());
	cout << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
