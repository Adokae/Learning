# include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
/*
ְ������ϵͳ��
����C++ʵ�ֻ��ڶ�̬��ְ������ϵͳ
��˾��ְ�������ࣺ��ͨԱ���������ϰ壬
��Ҫ��ʾְ����š�ְ��������ְ����λ��ְ��
��ͨԱ��ְ����ɾ�����������
����ְ������ϰ彻���������·������Ա��
�ϰ�ְ�𣺹���˾ȫ������

����ϵͳ����Ҫʵ�ֵĹ������£�
1 �˳��������
2 ����ְ����Ϣ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�
ְ����ϢΪ��ְ����š����������ű��
3 ��ʾְ����Ϣ
4 ɾ����ְְ�������ձ��ɾ��ָ��ְ��
5 �޸�ְ����Ϣ��������޸�ְ��������Ϣ
6 ����ְ����Ϣ������ְ�����/�������������Ա��Ϣ
7 ��������򣺰�ְ����ţ�������������������û�ָ��
8 ��������ĵ�������ļ��м�¼������ְ����Ϣ�����ǰ��Ҫ�ٴ�ȷ�ϣ��Է���ɾ
*/
int main()
{
	// ʵ�����������
	WorkerManger wm;
	int choice = 0;// �û�ѡ����
	while (true)
	{
        // ���ó�Ա����-չʾ�˵���Ա
	    wm.Show_Menu();
		cout << "����ѡ���" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			// �˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:
			// ����ְ��
			wm.Add_Emp();
			break;
		case 2:
			// ��ʾְ��
			wm.Show_Emp();
			break;
		case 3:
			// ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:
			// �޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:
			// ����ְ��
			wm.Find_Emp();
			break;
		case 6:
			// ����ְ��
			wm.Sort_Emp();
			break;
		case 7:
			// ����ĵ�
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
