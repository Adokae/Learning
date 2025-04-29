#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "manager.h"

Manger::Manger(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// 显示个人信息
void Manger::showInfo()
{
	cout << "职工编号: " << this->m_ID
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给普通员工" << endl;
}
// 获取岗位名称
string Manger::getDeptName()
{
	return string("经理");
}