#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>


/*
ԤԼ���ʵ�֣�ʹ��map����Ƕ��map����
map<int, map<string, string>>��
int���ͱ�ʾ�ļ��еڼ�����¼
map<string, string>��ʾ������¼����Ӧ����Ϣ
*/

class OrderFile
{
public:
	// ���캯��
	OrderFile();

	// ����ԤԼ��¼
	void updateOrder();

	// ԤԼ����
	int m_Size;

	// ��¼����ԤԼ��Ϣ������
	map<int, map<string, string>> m_orderData;
};