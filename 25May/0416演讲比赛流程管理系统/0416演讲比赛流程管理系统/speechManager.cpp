#include <iostream>
using namespace std;
#include "speechManager.h"


/*
创建管理类：
1 提供菜单界面与用户交互
2 对演讲比赛流程进行控制
3 与文件的读写交互

*/
// 构造函数
SpeechManager::SpeechManager()
{
	// 初始化容器和属性
	this->initSpeech();

	// 创建12名选手
	this->createSpeacher();

	// 加载往届文件记录
	this->loadRecord();
}

// 展示菜单
void SpeechManager::show_Menu()
{
	cout << "*******************************" << endl;
	cout << "********* 欢迎比赛  ***********" << endl;
	cout << "********* 1 开始演讲比赛 ******" << endl;
	cout << "********* 2 查看往届记录 ******" << endl;
	cout << "********* 3 清空比赛记录 ******" << endl;
	cout << "********* 0 退出比赛程序 ******" << endl;
	cout << endl;
}
// 创建12名选手
void SpeechManager::createSpeacher()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		// 创建具体选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		// 创建选手编号 并放入到v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手 放入map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
		//m_Speaker是一个map容器，
	}
}

// 开始比赛 比赛整体流程
void SpeechManager::startSpeech()
{
	// 第一轮比赛

	// 抽签
	this->speechDraw();

	// 比赛
	this->speechContest();

	// 显示晋级结果
	this->showScore();

	// 第二轮比赛
    this->m_Index++;
	// 抽签
	this->speechDraw();

	// 比赛
	this->speechContest();

	// 显示最终结果
	this->showScore();

	// 保存分数到文件中
	this->saveRecord();

	// 重置比赛 获取记录
	// 初始化容器和属性
	this->initSpeech();

	// 创建12名选手
	this->createSpeacher();

	// 加载往届文件记录
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

// 抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_Index == 1)
	{
		// 第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else if(this->m_Index == 2)
	{
		// 第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "------------------------------" << endl;
	//system("pause");
	cout << endl;
}

// 比赛
void SpeechManager::speechContest()
{
	cout << "-----------第" << this->m_Index << "轮比赛正式开始------------" << endl;
	// 使用临时容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0; // 统计小组人数
	
	vector<int>v_Src; // 比赛选手容器
	if (this->m_Index == 1)
	{
		// 第一轮比赛
		v_Src = v1;
	}
	else if (this->m_Index == 2)
	{
		// 第二轮比赛
		v_Src = v2;
	}
	// 遍历所有选手进行比赛
	// *it指的是选手编号
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// 评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 60-100之间的分数
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum / (double)d.size(); //把整型转换为double类型 使avg为double类型
		
		// 打印平均分
		/*cout << "编号" << *it << "姓名：" << this->m_Speaker[*it].m_Name <<
			" 分数 = " << avg << endl;*/

		// 把平均分放到map容器中
		// *it表示选手编号，通过m_Speaker[*it]指向选手，选手属性有姓名和成绩
		// 而且成绩是一个二元数组
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		// 将打分容器放入到临时小组容器
		groupScore.insert(make_pair(avg, *it));// 
		// 每六个人取前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			//groupScore中第一个double表示成绩 第二个int表示成员编号
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].m_Name
					<< " 成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			// 取走前三名
			int count = 0; // 取走人数计数
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else if (this->m_Index == 2)
				{
					vVictory.push_back((*it).second);
				}
				count++;
			}
			groupScore.clear();
			cout << endl;
		}

	}
	cout << "-----------第" << this->m_Index << "轮比赛完毕---------" << endl;
	system("pause");
}

// 显示晋级后的得分
void SpeechManager::showScore()
{
	cout << "----------------第" << this->m_Index << "轮晋级选手信息如下：--------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else if (this->m_Index == 2)
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号:" << *it << "姓名：" << this->m_Speaker[*it].m_Name <<
			" 分数：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}


// 保存分数
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用追加的方式写文件

	// 将最终胜利的选手数据写入文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();// 关闭文件

	cout << "记录已经保存" << endl;

	// 文件有记录 将文件是否存在改为存在
	this->fileIsEmpty = false;
}

// 读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);// 读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件打开失败" << endl;
		ifs.close();
	}
	// 文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);// 将上面读取的单个字符放回来

	int index = 0; //表示届数

	string data;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector <string>v;// 存放6个string的字符串

		int pos = -1; // 查找","位置的变量
		int start = 0; // 查找的开始位置
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				// 没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			/*cout << temp << endl;*/

			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "冠军编号:" << it->second[0] << "分数：" << it->second[1] << endl;
	}*/
}


// 显示往届记录
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者文件不存在！" << endl;
	}
	for (int i = 0;  i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号:" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			<< "亚军编号:" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			<< "季军编号:" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

// 退出功能
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


// 初始化容器
void SpeechManager::initSpeech()
{
	// 容器都置为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;

	// 将记录的容器也清空
	this->m_Record.clear();
}

// 清空记录
void SpeechManager::clearRecord()
{
	cout << "是否确定清空?" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs("speech.csv", ios::trunc); 
		// ios::trunc表示截断文件，当打开文件时，文件若已经存在，内容会被清空
		ofs.close();

		// 重置比赛 获取记录
		// 初始化容器和属性
		this->initSpeech();

		// 创建12名选手
		this->createSpeacher();

		// 加载往届文件记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

// 析构函数
SpeechManager::~SpeechManager()
{

}


