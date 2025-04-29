# include <iostream>
using namespace std;
#include <map>
#include <vector>

#define CHEHUA 0
#define MEISHU 1
#define YANGFA 2
/*
案例描述：
招聘10个员工，员工信息有姓名 工资组成 部分有：策划 美术 研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key（部门编号） value（员工）
分部门展示员工信息

实现步骤：
1 创建10名员工 放到vector中
2 遍历vector容器 对每个员工进行随机分组
3 分组后 将员工部门编号为key 具体员工为vlaue 放入到multimap容器中
4 分部门展示员工信息

*/
class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}


// 员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 产生随机部门编号
		int deptID = rand() % 3;

		m.insert(make_pair(deptID, *it));
	}

}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部分：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);// 统计部门人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名为：" << pos->second.m_Name << " 薪酬为： " << pos->second.m_Salary << endl;
	}

	cout << "美术部分：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);// 统计部门人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名为：" << pos->second.m_Name << " 薪酬为： " << pos->second.m_Salary << endl;
	}


	cout << "研发部分：" << endl;
	pos = m.find(YANGFA);
	count = m.count(YANGFA);// 统计部门人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名为：" << pos->second.m_Name << " 薪酬为： " << pos->second.m_Salary << endl;
	}
}

int main()
{
	// 创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "name = " << it->m_Name << " Salary = " << it->m_Salary << endl;
	}*/

	// 员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);


	// 分组展示员工
	showWorkerByGroup(mWorker);
	system("pause");

	return 0;
}
