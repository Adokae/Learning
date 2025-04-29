#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
using namespace std;

// ����ݽ���
class SpeechManager
{
public:
	// ���캯��
	SpeechManager();

	// չʾ�˵�
	void show_Menu();

	// �˳�����
	void exitSystem();

	// ��������
	~SpeechManager();

	// ��ʼ������
	void initSpeech();

	// ����12��ѡ��
	void createSpeacher();

	// ��ʼ���� ������������
	void startSpeech();

	// ��ǩ
	void speechDraw();

	// ����
	void speechContest();

	// ��ʾ�÷�
	void showScore();

	// �������
	void saveRecord();

	// ��ȡ��¼
	void loadRecord();

	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	// ��������¼������
	map<int, vector<string>> m_Record;

	// ��ʾ�����¼
	void showRecord();

	// ��ռ�¼
	void clearRecord();

	// ��ӳ�Ա����
	// ��һ�ֱ���ѡ�ֱ��
	vector<int>v1;

	// ��һ�ֽ���ѡ�ֱ��
	vector<int>v2;

	// ����ʤ����ǰ����ѡ�ֱ��
	vector<int>vVictory;

	// ��ű�ż����Ӧ������
	map<int, Speaker>m_Speaker;

	// ��ŵ�ǰ��������
	int m_Index;
};
