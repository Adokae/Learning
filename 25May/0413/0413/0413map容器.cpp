# include <iostream>
using namespace std;
#include <map>

/*
map�����������
1 map������Ԫ�ض���pair
2 pair�е�һ��Ԫ��Ϊkey(��ֵ) ���������� �ڶ���Ԫ��Ϊvalue��ʵֵ��
3 ����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

���ʣ�
map1/multimap���ڹ���ʽ���� �ײ�ṹ���ö�����ʵ��

�ŵ㣺
1 ���Ը���keyֵ�����ҵ�valueֵ

map��multimap����
1 map�������������������ظ�keyֵԪ��
2 multimap�������������ظ�keyֵԪ��

map����͸�ֵ��
���죺
1 map<T1, T2> mp Ĭ�Ϲ��캯��
2 map(const map &mp); �������캯��

��ֵ��
map& operator=(const map &mp) ����=������
*/
void printMap(map<int, int>& mp)
{
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "keyֵ" << (*it).first << " valueֵ" << (*it).second << endl;
	}
	cout << endl;
}


void test1()
{
	map<int, int>m;
	// Ĭ�ϰ�keyֵ��������
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	// ��������
	map<int, int>m2(m);
	printMap(m2);

	// ��ֵ
	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}
int main()
{
	test1();
	system("pause");

	return 0;
}
