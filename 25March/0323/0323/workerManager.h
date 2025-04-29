#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream>// �������������ͷ�ļ�
using namespace std;// ʹ�ñ�׼�����ռ�

// ������ְ���������������û�����
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"



class WorkerManger
{
public:

	// ���캯��
	WorkerManger();

	// չʾ�˵�
	void Show_Menu();

	// �˳�ϵͳ
	void ExitSystem();

	// ��¼ְ������
	int m_EmpNum;
	// ְ������ָ��
	Worker** m_EmpArray; // ��ʾָ��ָ���ָ��
	// ���ְ��
	void Add_Emp();

	// �����ļ�
	void save();

	// �ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty; // ��־�ļ��Ƿ�Ϊ��

	// ͳ������
	int get_EmpNum();

	// ��ʼ��Ա��
	void init_Emp();

	// ��ʾְ��
	void Show_Emp();

	// ɾ��ְ��
	void Del_Emp();

	// �ж�ְ���Ƿ����
	int IsExist(int id);

	// �޸�
	void Mod_Emp();

	// ����
	void Find_Emp();

	// ����
	void Sort_Emp();

	// ����ļ�
	void Clean_File();

	// ��������
	~WorkerManger();

};
