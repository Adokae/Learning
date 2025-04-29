# include <iostream>
using namespace std;
#include <list>
/*
list������
���ܣ������ݽ�����ʽ�洢

��������洢��Ԫ�ϵķ������Ĵ洢�ṹ ����Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ��

������һϵ�н�����

������ɽṹ��һ���洢����Ԫ�ص���������һ���Ǵ洢��һ������ָ����

STL�е�������һ��˫��ѭ������һ��Ԫ���о�������ָ�룬һ��ָ��ǰ��Ԫ�صĵ�ַ��һ��ָ�����Ԫ��
�ĵ�ַ�����һ���ڵ��nextָ���ʼԪ�أ��ʼԪ�ص�prevָ�����һ��Ԫ�ء�

�ŵ㣺�ɶ�����λ�ý��п��ٲ����ɾ��
ȱ�㣺�����ٶȣ�û������죬ռ�ÿռ���������

����list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������

list���������ɾ���������������ԭ��list��������ʧЧ������vector���ǲ�������:
��list�в����ɾ��������ʹ����Ԫ�ص����ݺ͵�ַʧЧ������vector�У�����������������
vector�������������¿����ڴ�ռ䣬���ԭ������ָ��һ���µĵ�ַ

���캯����
����list����
1:list<T>lst;list����ģ����ʵ�ֶ����Ĭ�Ϲ�����ʽ
2 list(beg,end); ���캯����[beg,end)�����Ԫ�ؿ���������
3 list(n,elem);���캯����n��elem����������
4 list(const list &lst);�������캯��
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// ����list����
	list<int>L1;// Ĭ�Ϲ���

	// �������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// ��������
	printList(L1);


	// ���䷽ʽ����
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	// ��������
	list<int>L3(L2);
	printList(L3);

	// n��elem
	list<int>L4(10, 1000);
	printList(L4);
}


int main()
{
	test1();
	system("pause");

	return 0;
}
