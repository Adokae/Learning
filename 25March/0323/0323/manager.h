#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// ��ͨԱ���ļ�
class Manger :public Worker
{
public:
	Manger(int id, string name, int dId);

	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getDeptName();
};