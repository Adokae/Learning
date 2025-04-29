# include <iostream>
using namespace std;
# include <string>
/*
结构体指针：
通过指针访问结构体中的成员

利用操作符->可以通过结构体指针访问结构体属性
*/

struct Student
{

	string name;
	int age;
	int score;
};
int main()
{
	Student stu = { "张三", 18, 100 };
	struct Student* p = &stu;
	// 通过指针访问结构体中数据变量
	// 通过结构体指针 访问结构体中属性 需要利用"->"

	cout << "姓名： " << p->name << endl;

	system("pause");

	return 0;
}
