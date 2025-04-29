# include <iostream>
using namespace std;
#include <string>

// 结构体中const使用场景

struct Student
{
	string name;
	int age;
	int score;
};


// 若函数改为指针传递，函数形参变为指针，可节约内存空间
// 且不会复制新的副本
void printStruct(const struct Student * s)
{
	// 函数加入const，一旦有修改操作就会报错，防止误操作
	cout << s->name << endl;
	cout << s->age << endl;
	cout << s->score << endl;

}

int main()
{
	Student s = { "张三" , 17, 78};
	// 假设学生有很多，所复制输出的代码量也越多
	printStruct(&s);

	system("pause");

	return 0;
}
