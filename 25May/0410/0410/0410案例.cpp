# include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
/*
��������ί���
������5��ѡ�֣�ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣�ȡƽ����

ʵ�֣�
1 ����5��ѡ�� �ŵ�vector��
2 ����vector���� ȡ����ÿһ��ѡ�� ִ��forѭ�� ��10�����ַŵ�deque������
3 sort�㷨��deque�����еķ������� ȥ����ߺ���ͷ�
4 deque��������һ�� �ۻ��ܷ�
5 ��ȡƽ����
*/

// ѡ����
class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void createPerson(vector<Person> &v) 
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// ����ί��������deque������
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60; // 60~100
			d.push_back(score);
		}
		// ����
		sort(d.begin(), d.end());
		// ȥ����߷ֺ���ͷ�
		d.pop_front();
		d.pop_back();

		// ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);
		}
		int avg = sum / d.size();

		// ƽ���ָ�ֵ��ѡ��
		it->m_Score = avg;
	}
}

int main()
{
	// ������������
	srand((unsigned int)time(NULL));


	//1 ����5��ѡ��
	vector<Person> v;
	createPerson(v);
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
	//	//cout << it->m_Name << "����Ϊ��" << it->m_Score << endl;// it��ָ��
	//	cout << (*it).m_Name << "����Ϊ��" << (*it).m_Score << endl;
	//}

	// 2 ��ѡ�ִ��
	setScore(v);

	// 3 ��ʾ
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << it->m_Name << "����Ϊ��" << it->m_Score << endl;// it��ָ��
		cout << (*it).m_Name << "����Ϊ��" << (*it).m_Score << endl;
	}

	system("pause");

	return 0;
}
