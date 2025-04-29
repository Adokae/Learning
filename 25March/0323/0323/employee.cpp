using namespace std;
#include "employee.h"

Employer::Employer(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// 显示个人信息
void Employer::showInfo()
{
	cout << "职工编号: " << this->m_ID
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName() 
		<< "\t岗位职责：完成经理交给的任务"  << endl;
}
// 获取岗位名称
string Employer::getDeptName()
{
	return string("员工");
}