# include <iostream>
using namespace std;
# include <string>
# include <ctime>
// ����ʱ���ͷ�ļ�

/*
�ṹ�尸��1��
ÿ����ʦ��5��ѧ�����ܹ���3����ʦ
���ѧ������ʦ�Ľṹ�壬����ʦ�Ľṹ���У������ʦ������
5��ѧ����������Ϊ��Ա
ѧ���ĳ�Ա������ ���Է���

����������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
���մ�ӡ�����ʦ�������ʦ����ѧ������
*/
struct Student
{
	string stu_name;
	int score;
};

struct Teacher
{
	string teacher_name;
	struct Student stu[5]; // ��һά�����ʾ
};

// ���뺯��
void input(struct Teacher teachers[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		teachers[i].teacher_name = "Teacher_";
		teachers[i].teacher_name += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			teachers[i].stu[j].stu_name = "Student_";
			teachers[i].stu[j].stu_name += nameSeed[j];
			int score = rand()%61 + 40;
			//printf("�����%d����ʦ�ĵ�%d��ѧ������:", i+1, j+1);
			//cin >> score;
			teachers[i].stu[j].score = score;
		}
	}
}
	// �������
void printput(struct Teacher teachers[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������" << teachers[i].teacher_name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "ѧ��������" << teachers[i].stu[j].stu_name << endl;
			cout << "ѧ���ɼ���" << teachers[i].stu[j].score << endl;
		}
	}
}


int main()
{
	// ���������
	srand((unsigned int)time(NULL));

	struct Teacher teachers[3];
	int len = sizeof(teachers) / sizeof(teachers[0]);
	input(teachers, len);
	printput(teachers, len);

	system("pause");
	return 0;
}
