# include <iostream>
using namespace std;
#include <map>

/*
map���Һ�ͳ��

1 find(key) ���key�Ƿ���ڣ����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end()
2 count(key) ͳ��key��Ԫ�ظ���
*/
void test1()
{
	// ����
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
//m.insert(make_pair(3, 40)); // �޷�����

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "���ҵ�Ԫ��key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}


	// ͳ�� map����������ظ�keyԪ�� numҪôΪ0 ҪôΪ1
	int num = m.count(3);
	cout << "num = " << num << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
