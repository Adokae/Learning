# include <iostream>
using namespace std;

/*
结构体嵌套：结构体中的成员可以是另一个结构体

示例：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
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
	// 结构体嵌套
	// 创建老师
	Teacher t = { 1000, "王老师", 30, {"小王", 17, 90}};
	/*t.id = 10000;
	t.name = "王老师";
	t.age = 30;
	t.stu.name = "张三";
	t.stu.age = 17;
	t.stu.score = 99;*/
	cout << "学生成绩" << t.stu.score << endl;
	system("pause");

	return 0;
}
