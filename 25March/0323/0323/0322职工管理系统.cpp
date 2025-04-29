# include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
/*
职工管理系统：
利用C++实现基于多态的职工管理系统
公司中职工分三类：普通员工、经理、老板，
需要显示职工编号、职工姓名、职工岗位、职责
普通员工职责：完成经理交给的任务
经理职责：完成老板交给的任务，下发任务给员工
老板职责：管理公司全体事务

管理系统中需要实现的功能如下：
1 退出管理程序
2 增加职工信息，批量添加职工功能，将信息录入到文件中，
职工信息为：职工编号、姓名、部门编号
3 显示职工信息
4 删除离职职工：按照编号删除指定职工
5 修改职工信息：按编号修改职工个人信息
6 查找职工信息：按照职工编号/姓名查找相关人员信息
7 按编号排序：按职工编号，进行排序，排序规则由用户指定
8 清空所有文档：清空文件中记录的所有职工信息，清空前需要再次确认，以防误删
*/
int main()
{
	// 实例化管理对象
	WorkerManger wm;
	int choice = 0;// 用户选择项
	while (true)
	{
        // 调用成员函数-展示菜单成员
	    wm.Show_Menu();
		cout << "输入选择项：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			// 退出系统
			wm.ExitSystem();
			break;
		case 1:
			// 增加职工
			wm.Add_Emp();
			break;
		case 2:
			// 显示职工
			wm.Show_Emp();
			break;
		case 3:
			// 删除职工
			wm.Del_Emp();
			break;
		case 4:
			// 修改职工
			wm.Mod_Emp();
			break;
		case 5:
			// 查找职工
			wm.Find_Emp();
			break;
		case 6:
			// 排序职工
			wm.Sort_Emp();
			break;
		case 7:
			// 清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}

	system("pause");

	return 0;
}
