# include <iostream>
using namespace std;
#include <map>
/*
map�����ɾ��

������
1 insert(elem); �������в���Ԫ��
2 clear()�������Ԫ��
3 erase(pos) ɾ��pos��������ָ��Ԫ�� ������һ��Ԫ�صĵ�����
4 erase(beg,end) ɾ������[beg,end)������Ԫ�� ������һ��Ԫ�صĵ�����
5 erase(key) ɾ��������ֵΪkey��Ԫ��


*/
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "keyֵ" << (*it).first << " valueֵ" << (*it).second << endl;
	}
	cout << endl;
}



void test1()
{
	map<int, int>m1;
	// ����
	m1.insert(pair<int, int>(1, 10));

	m1.insert(make_pair(2, 20));

	m1.insert(map<int, int>::value_type(3, 20));

	// ����ʹ��[]ͨ��key����value
	m1[4] = 40;
	// ������ʹ�ø��ַ�ʽ���в�ֵ �������ڸü�ֵ�� ���ᴴ���ü�ֵ�� Ĭ��ֵΪ0

	//cout << m1[5] << endl;
	cout << m1[4] << endl;
	printMap(m1);

	// ɾ��
	m1.erase(m1.begin());
	printMap(m1);

	m1.erase(3);//��keyɾ��
	printMap(m1);

	//m1.erase(m1.begin(), m1.end());
	m1.clear();
	printMap(m1);


}
int main()
{
	test1();
	system("pause");

	return 0;
}
