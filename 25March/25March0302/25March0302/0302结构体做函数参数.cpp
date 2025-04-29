# include <iostream>
using namespace std;
# include <string>
/*
结构体做函数参数：
将结构体作为函数参数向函数中传递

传递方式有两种：
1 值传递
2 地址传递
*/

struct Student
{
	string name;
	int age;
	int score;
};

// 打印学生信息的函数

// 值传递
void printStudent(struct Student stu)
{
	stu.age = 50; // 形参的值有所改变，实参值不改变
	cout << stu.name << endl;
	cout << stu.age << endl;
	cout << stu.score << endl;
}

// 地址传递
void printStudent2(struct Student * p)
{
	p->age = 90; // 实参值也发生改变
	cout << p->name << endl;
	cout << p->age << endl;
	cout << p->score << endl;
}

int main()
{
	struct Student stu = {"张三", 25, 90};
	
	// 结构体做函数参数
	// 将学生传入到一个参数中，打印学生身上的所有信息
	printStudent(stu);
	printStudent2(&stu);

	system("pause");

	return 0;
}
