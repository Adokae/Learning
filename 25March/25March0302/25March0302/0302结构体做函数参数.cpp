# include <iostream>
using namespace std;
# include <string>
/*
�ṹ��������������
���ṹ����Ϊ�������������д���

���ݷ�ʽ�����֣�
1 ֵ����
2 ��ַ����
*/

struct Student
{
	string name;
	int age;
	int score;
};

// ��ӡѧ����Ϣ�ĺ���

// ֵ����
void printStudent(struct Student stu)
{
	stu.age = 50; // �βε�ֵ�����ı䣬ʵ��ֵ���ı�
	cout << stu.name << endl;
	cout << stu.age << endl;
	cout << stu.score << endl;
}

// ��ַ����
void printStudent2(struct Student * p)
{
	p->age = 90; // ʵ��ֵҲ�����ı�
	cout << p->name << endl;
	cout << p->age << endl;
	cout << p->score << endl;
}

int main()
{
	struct Student stu = {"����", 25, 90};
	
	// �ṹ������������
	// ��ѧ�����뵽һ�������У���ӡѧ�����ϵ�������Ϣ
	printStudent(stu);
	printStudent2(&stu);

	system("pause");

	return 0;
}
