# include <iostream>
using namespace std;
# include <string>

/*
结构体的基本概念：
用户自定义的数据类型，允许用户存储不同的数据类型
实际上是一类数据类型的集合
语法： struct 结构体名 {结构体成员列表}；

通过结构体创建变量的方式有以下三种：
1 struct 结构体名 变量名
2 struct 结构体名 变量名 = {成员1值，成员2值，...}
3 定义结构体时顺便创建变量



*/

//实例：
//创建学生数据类型 学生包括姓名 年龄 分数
struct Student
{
	// 成员列表

	// 姓名
	string name;
	// 年龄
	int age;
	//分数
	int score;
} s3;  // 顺便创建一个结构体变量



int main()
{
	//通过数据类型创建具体学生
	//方式1
	struct Student s1;  // 创建时，关键字可以省略
	// 给s1属性赋值，通过.(点)访问结构体变量中的属性
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;
	cout << "s1的相关内容：" << s1.name << s1.age << s1.score << endl;

	//方式2
	struct Student s2 = {"李四", 19, 80};
	cout << "s2的相关内容：" << s2.name << s2.age << s2.score << endl;
	


	// 方式3 见上述创建结构体
	s3.name = "王五";
	s3.age = 30;
	s3.score = 99;
	cout << "s3的相关内容：" << s3.name << s3.age << s3.score << endl;
	
	
	system("pause");
	return 0;
}
