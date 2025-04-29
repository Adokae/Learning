# include <iostream>
using namespace std;
#include "speechManager.h"
#include <ctime>
/*
演讲比赛，共12个人参加，比赛共两轮：第一轮淘汰赛，第二轮决赛
每名选手具有对应编号：10001-10012
比赛方式：分组比赛，每组6个人
第一轮分两个小组，整体按选手编号进行抽签后顺序演讲
十个评委分别给每个选手打分，去除最高分和最低分，求取的平均分为本轮选手的比赛
小组演讲完后，淘汰组内最后三名选手，前三名晋级，
第二轮为决赛，前三名胜出
每轮比赛过后显示晋级选手的信息


程序功能：
1 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一
阶段
2 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv保存
3 清空比赛记录：将文件中数据清空
4 退出比赛程序：可以退出当前程序

*/
int main()
{
	// 创建随机数种子
	srand((unsigned int)time(NULL));

	// 创建对象
	SpeechManager sm;

	// 测试是否创建12名选手
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first << " 姓名:" << it->second.m_Name << " 分数：" <<
			it->second.m_Score[0] << endl;
	}*/
	
	while (true)
	{	
		sm.show_Menu();

		cout << "请输入选项:" << endl;
		int choice = 0;//  存储用户输入
		cin >> choice;

		switch (choice)
		{
		case 1:// 开始比赛
			sm.startSpeech();
			break;
		case 2:// 查看往届比赛记录
			sm.showRecord();
			break;
		case 3:// 清空比赛记录
			sm.clearRecord();
			break;
		case 0:// 退出比赛
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
