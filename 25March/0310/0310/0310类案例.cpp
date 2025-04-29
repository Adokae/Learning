# include <iostream>
using namespace std;
# include <string>

/*
类中的属性和行为，统称为成员
属性：成员属性 成员变量
行为：成员函数 成员方法

*/
class Student
{
public:
	string name;
	string ID;
	void assignment()
	{
		cout << "输入要赋值的姓名：" << endl;
		cin >> name;
		cout << "输入要赋值的学号：" << endl;
		cin >> ID;
	}
	void Print()
	{
		cout << "姓名："<< name << endl;
		cout << "学号：" << ID << endl;
	}

};
int main()
{
	Student stu;
	stu.name = "张三";
	stu.ID = "123";

	stu.Print();
	stu.assignment();
	stu.Print();
	system("pause");

	return 0;
}
