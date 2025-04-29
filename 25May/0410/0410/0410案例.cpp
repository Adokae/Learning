# include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
/*
案例：评委打分
描述：5名选手，ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均分

实现：
1 创建5名选手 放到vector中
2 遍历vector容器 取出来每一个选手 执行for循环 把10个评分放到deque容器中
3 sort算法对deque容器中的分数排序 去除最高和最低分
4 deque容器遍历一遍 累积总分
5 获取平均分
*/

// 选手类
class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void createPerson(vector<Person> &v) 
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// 将评委分数放入deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60; // 60~100
			d.push_back(score);
		}
		// 排序
		sort(d.begin(), d.end());
		// 去除最高分和最低分
		d.pop_front();
		d.pop_back();

		// 取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);
		}
		int avg = sum / d.size();

		// 平均分赋值给选手
		it->m_Score = avg;
	}
}

int main()
{
	// 添加随机数种子
	srand((unsigned int)time(NULL));


	//1 创建5名选手
	vector<Person> v;
	createPerson(v);
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
	//	//cout << it->m_Name << "分数为：" << it->m_Score << endl;// it是指针
	//	cout << (*it).m_Name << "分数为：" << (*it).m_Score << endl;
	//}

	// 2 给选手打分
	setScore(v);

	// 3 显示
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << it->m_Name << "分数为：" << it->m_Score << endl;// it是指针
		cout << (*it).m_Name << "分数为：" << (*it).m_Score << endl;
	}

	system("pause");

	return 0;
}
