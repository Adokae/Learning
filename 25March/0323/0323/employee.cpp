using namespace std;
#include "employee.h"

Employer::Employer(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// ��ʾ������Ϣ
void Employer::showInfo()
{
	cout << "ְ�����: " << this->m_ID
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName() 
		<< "\t��λְ����ɾ�����������"  << endl;
}
// ��ȡ��λ����
string Employer::getDeptName()
{
	return string("Ա��");
}