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

// 设计演讲类
class SpeechManager
{
public:
	// 构造函数
	SpeechManager();

	// 展示菜单
	void show_Menu();

	// 退出功能
	void exitSystem();

	// 析构函数
	~SpeechManager();

	// 初始化容器
	void initSpeech();

	// 创建12名选手
	void createSpeacher();

	// 开始比赛 比赛整体流程
	void startSpeech();

	// 抽签
	void speechDraw();

	// 比赛
	void speechContest();

	// 显示得分
	void showScore();

	// 保存分数
	void saveRecord();

	// 读取记录
	void loadRecord();

	// 判断文件是否为空
	bool fileIsEmpty;

	// 存放往届记录的容器
	map<int, vector<string>> m_Record;

	// 显示往届记录
	void showRecord();

	// 清空记录
	void clearRecord();

	// 添加成员属性
	// 第一轮比赛选手编号
	vector<int>v1;

	// 第一轮晋级选手编号
	vector<int>v2;

	// 最终胜出的前三名选手编号
	vector<int>vVictory;

	// 存放编号及其对应的人名
	map<int, Speaker>m_Speaker;

	// 存放当前比赛轮数
	int m_Index;
};
