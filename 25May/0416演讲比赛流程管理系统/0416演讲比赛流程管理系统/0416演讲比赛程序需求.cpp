# include <iostream>
using namespace std;
#include "speechManager.h"
#include <ctime>
/*
�ݽ���������12���˲μӣ����������֣���һ����̭�����ڶ��־���
ÿ��ѡ�־��ж�Ӧ��ţ�10001-10012
������ʽ�����������ÿ��6����
��һ�ַ�����С�飬���尴ѡ�ֱ�Ž��г�ǩ��˳���ݽ�
ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣���ȡ��ƽ����Ϊ����ѡ�ֵı���
С���ݽ������̭�����������ѡ�֣�ǰ����������
�ڶ���Ϊ������ǰ����ʤ��
ÿ�ֱ���������ʾ����ѡ�ֵ���Ϣ


�����ܣ�
1 ��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ
�׶�
2 �鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv����
3 ��ձ�����¼�����ļ����������
4 �˳��������򣺿����˳���ǰ����

*/
int main()
{
	// �������������
	srand((unsigned int)time(NULL));

	// ��������
	SpeechManager sm;

	// �����Ƿ񴴽�12��ѡ��
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << " ����:" << it->second.m_Name << " ������" <<
			it->second.m_Score[0] << endl;
	}*/
	
	while (true)
	{	
		sm.show_Menu();

		cout << "������ѡ��:" << endl;
		int choice = 0;//  �洢�û�����
		cin >> choice;

		switch (choice)
		{
		case 1:// ��ʼ����
			sm.startSpeech();
			break;
		case 2:// �鿴���������¼
			sm.showRecord();
			break;
		case 3:// ��ձ�����¼
			sm.clearRecord();
			break;
		case 0:// �˳�����
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}

	}

	system("pause");

	return 0;
}
