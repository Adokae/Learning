# include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
/*
机房预约系统要求：
1 身份：
学生:申请使用机房
老师：审核学生预约申请
管理员：给老师、学生创建账户

2 机房：
1号机房：最大容量20人
2号机房：最大容量50人
3号机房：最大容量100人

3申请
申请订单没有由管理员负责清空
学生预约未来一周内的机房使用，预约日期为周一到周五，预约时段需选择上午还是下午
教师审核预约，根据实际情况审核预约通过或不通过

系统具体需求：
1 首先进入登录界面，可选登录身份
学生代表、老师、管理员、退出

2 每个身份都需要验证后进行子菜单
学生需要输入：学号 姓名 登录密码
老师          职工号 姓名 登录密码
管理员需要输入 管理员姓名 登录密码

3 学生具体功能
3.1 申请预约机房
3.2 查看自身预约状态
3.3 查看全部预约信息以及预约状态
3.4 取消自身预约，预约成功或审核中的预约均可取消
3.5 注销登录 退出登录

4 教师具体功能
4.1 查看全部预约信息以及预约状态
4.2 对学生预约进行审核
4.3 注销登录

5 管理员具体功能
5.1 添加学生或教师账号，需要注意学生和教师账号不能重复
5.2 查看学生或教师全部信息
5.3 查看所有机房信息
5.4 清空所有预约记录
5.5 注销登录
*/

// 进入老师子菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		// 调用老师子菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// 查看所有人预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			// 审核预约
			tea->validOrder();
		}
		else
		{
			// 注销登录
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 进行学生子菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		// 调用学生子菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select;
		cin >> select;
		if (select == 1)
		{
			// 申请预约
			stu->applyOrder();
		}
		else if (select == 2)
		{
			// 查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			// 查看所有人预约
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			// 取消预约
			stu->cancelOrder();
		}
		else
		{
			// 注销登录
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}


// 进入管理员的子菜单
// 传入函数的是一个指向Identity类型的指针，该指针是manager的引用
void managerMenu(Identity * &manager)
{
	while (true)
	{
		// 调用管理员的子菜单
		manager->operMenu();

		// 将父类指针 转换为i子类指针 调用子类中的其它接口
		Manager* man = (Manager*)manager;// 强制类型转换 将父类Identity指针强制转换为子类指针Manager
		int select;
		cin >> select;
		if (select == 1)
		{
			// 添加账号
			//cout << "添加账号" << endl;
			man->addPerson();

		}
		else if (select == 2)
		{
			// 查看账号
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			// 查看机房
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			// 清空预约
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			cout << "注销登录" << endl;
			delete manager;// 销毁掉堆区数据
			cout << "注销登录成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
// 登录功能
// 参数1-操作文件名 参数2-操作身份类型
void LogIn(string fileName, int type)
{
	Identity* person = NULL;// 父类指针 用于指向子类对象
	// 读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// 判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
	}
	// 准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		// 学生身份
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		// 老师身份
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		// 学生身份验证
		int fId;// 从文件中读取的id号
		string fName;// 从文件中读取的姓名
		string fPwd;// 从文件中读取的密码
		while (ifs>>fId && ifs >> fName && ifs >> fPwd)
		{
			 //用户输入信息与现有文件中的信息一致
			// 目前直接向student.txt文档中写入两行数据，但读取的时候出现乱码情况
			//原因是：文件以UTF-8编码保存，C++使用本地编码(可能是GBK) 导致读取时无法正确
			// 先对学生姓名使用英文
			// 解析中文字符
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				// 进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// 老师身份验证
		int fId;// 从文件中读取的id号
		string fName;// 从文件中读取的姓名
		string fPwd;// 从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//用户输入信息与现有文件中的信息一致
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师身份验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				// 进入老师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		// 管理员身份验证
		string fName;// 从文件中读取的姓名
		string fPwd;// 从文件中读取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			//用户输入信息与现有文件中的信息一致
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员身份验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// 进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select;
	while (true)
	{
		cout << "======================= 欢迎进入机房预约系统  =====================" << endl;
		cout << endl << "请输入身份：" << endl;
		cout << "\t\t -------------------------------\n" << endl;
		cout << "\t\t|          1.学生代表            |\n" << endl;
		cout << "\t\t|          2.老师                |\n" << endl;
		cout << "\t\t|          3.管理员              |\n" << endl;
		cout << "\t\t|          0.退出                |\n" << endl;
		cout << "\t\t  -------------------------------\n" << endl;
		cout << "请输入你的选择:";
		cin >> select;
		// 根据用户选择 实现不同功能
		switch (select)
		{
		case 1:// 学生身份
			LogIn(STUDENT_FILE, 1);
			break;
		case 2:// 老师身份
			LogIn(TEACHER_FILE, 2);
			break;
		case 3:// 管理员身份
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:// 退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	system("pause");

	return 0;
}
