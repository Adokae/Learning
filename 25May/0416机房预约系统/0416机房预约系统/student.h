#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "computerRoom.h"
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

class Student : public Identity
{
public:
	// Ĭ�Ϲ���
	Student();

	// �вι���
	Student(int id, string name, string pwd);

	// �˵�����
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴����ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();
	
	// ȡ��ԤԼ
	void cancelOrder();

	// ѧ��ѧ��
	int m_Id;

	// ������Ϣ
	vector<ComputerRoom>vCom;
};