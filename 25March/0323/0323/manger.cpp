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

// ��ʾ������Ϣ
void Manger::showInfo()
{
	cout << "ְ�����: " << this->m_ID
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·��������ͨԱ��" << endl;
}
// ��ȡ��λ����
string Manger::getDeptName()
{
	return string("����");
}