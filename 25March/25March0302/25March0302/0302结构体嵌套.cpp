# include <iostream>
using namespace std;

/*
�ṹ��Ƕ�ף��ṹ���еĳ�Ա��������һ���ṹ��

ʾ����ÿ����ʦ����һ��ѧԱ��һ����ʦ�Ľṹ���У���¼һ��ѧ���Ľṹ��
*/

struct Student
{
	string name;
	int age;
	int score;
};


struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};

int main()
{
	// �ṹ��Ƕ��
	// ������ʦ
	Teacher t = { 1000, "����ʦ", 30, {"С��", 17, 90}};
	/*t.id = 10000;
	t.name = "����ʦ";
	t.age = 30;
	t.stu.name = "����";
	t.stu.age = 17;
	t.stu.score = 99;*/
	cout << "ѧ���ɼ�" << t.stu.score << endl;
	system("pause");

	return 0;
}
