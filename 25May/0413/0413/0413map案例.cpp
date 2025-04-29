# include <iostream>
using namespace std;
#include <map>
#include <vector>

#define CHEHUA 0
#define MEISHU 1
#define YANGFA 2
/*
����������
��Ƹ10��Ա����Ա����Ϣ������ ������� �����У��߻� ���� �з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key�����ű�ţ� value��Ա����
�ֲ���չʾԱ����Ϣ

ʵ�ֲ��裺
1 ����10��Ա�� �ŵ�vector��
2 ����vector���� ��ÿ��Ա�������������
3 ����� ��Ա�����ű��Ϊkey ����Ա��Ϊvlaue ���뵽multimap������
4 �ֲ���չʾԱ����Ϣ

*/
class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}


// Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����������ű��
		int deptID = rand() % 3;

		m.insert(make_pair(deptID, *it));
	}

}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻����֣�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);// ͳ�Ʋ�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����Ϊ��" << pos->second.m_Name << " н��Ϊ�� " << pos->second.m_Salary << endl;
	}

	cout << "�������֣�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);// ͳ�Ʋ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����Ϊ��" << pos->second.m_Name << " н��Ϊ�� " << pos->second.m_Salary << endl;
	}


	cout << "�з����֣�" << endl;
	pos = m.find(YANGFA);
	count = m.count(YANGFA);// ͳ�Ʋ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����Ϊ��" << pos->second.m_Name << " н��Ϊ�� " << pos->second.m_Salary << endl;
	}
}

int main()
{
	// ����Ա��
	vector<Worker> vWorker;
	createWorker(vWorker);
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "name = " << it->m_Name << " Salary = " << it->m_Salary << endl;
	}*/

	// Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);


	// ����չʾԱ��
	showWorkerByGroup(mWorker);
	system("pause");

	return 0;
}
