# include <iostream>
using namespace std;
#include <queue>
/*
queue������
һ���Ƚ��ȳ������ݽṹ������������
�������������һ������Ԫ�� ����һ���Ƴ�Ԫ��
ֻ�ж�ͷ�Ͷ�β���ܱ����ʹ�� �������б�����Ϊ

��ӣ�push()
���ӣ�pop()

���ýӿڣ�
���캯����
1 queue<T> que; queue����ģ����ʵ�� queue�����Ĭ�Ϲ�����ʽ
2  queue(const queue &que); �������캯��

��ֵ������
1 queue& operator=(const queue &que); ����=������

���ݴ�ȡ��
1 push(elem);����β���Ԫ��
2 pop();�Ӷ�ͷ�Ƴ���һ��Ԫ��
3 back();�������һ��Ԫ��
4 front();���ص�һ��Ԫ��

��С������
1 empty();�ж϶�ջ�Ƿ�Ϊ��
2 size();����ջ�Ĵ�С

*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test1() {
	queue<Person>q;
	Person p1("a", 10);
	Person p2("b", 10);
	Person p3("c", 10);
	Person p4("d", 10);
	// ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "�Ƴ�Ԫ��֮ǰ���д�СΪ��" << q.size() << endl;

	while (!q.empty())
	{
		cout << "��ͷԪ��Ϊ������Ϊ��" << q.front().m_Name << "����Ϊ��" << q.front().m_Age << endl;

		cout << "��βԪ��Ϊ������Ϊ��" << q.back().m_Name << "����Ϊ��" << q.back().m_Age << endl;

		q.pop();
	}

	cout << "�Ƴ�Ԫ��֮����д�СΪ��" << q.size() << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}
