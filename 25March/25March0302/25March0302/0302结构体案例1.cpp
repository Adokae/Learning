# include <iostream>
using namespace std;
# include <string>
# include <ctime>
// 种子时间的头文件

/*
结构体案例1：
每名老师带5名学生，总共有3名老师
设计学生和老师的结构体，在老师的结构体中，存放老师姓名和
5名学生的数组作为成员
学生的成员有姓名 考试分数

创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印输出老师数组和老师所带学生数据
*/
struct Student
{
	string stu_name;
	int score;
};

struct Teacher
{
	string teacher_name;
	struct Student stu[5]; // 用一维数组表示
};

// 输入函数
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
			//printf("输入第%d个老师的第%d个学生分数:", i+1, j+1);
			//cin >> score;
			teachers[i].stu[j].score = score;
		}
	}
}
	// 输出函数
void printput(struct Teacher teachers[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << teachers[i].teacher_name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学生姓名：" << teachers[i].stu[j].stu_name << endl;
			cout << "学生成绩：" << teachers[i].stu[j].score << endl;
		}
	}
}


int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));

	struct Teacher teachers[3];
	int len = sizeof(teachers) / sizeof(teachers[0]);
	input(teachers, len);
	printput(teachers, len);

	system("pause");
	return 0;
}
