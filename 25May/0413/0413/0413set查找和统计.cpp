# include <iostream>
using namespace std;
#include <set>

/*
��set�������в��Һ�ͳ������

������
1 find(key); ����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end()
2 count(key); ͳ��key��Ԫ�ظ���


*/

void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	// ����
	set<int>::iterator pos = s1.find(300);
	if (pos != s1.end())
	{
		cout << "�ҵ�Ԫ��:" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

}
// ͳ��
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	// ͳ��30�ĸ���
	// ����set���� ͳ�ƽ��Ҫô��1 ҪôΪ0
	int num = s1.count(30);
	cout << "30�ĸ���Ϊ��" << num << endl;
}



int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
