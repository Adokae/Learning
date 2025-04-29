#include "workerManager.h"

WorkerManger::WorkerManger()
{
    // 1 文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);// 读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		// 初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// 文件为空
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// 文件存在 数据不为空
	int num = this->get_EmpNum();
	cout << "职工人数为: " << num << endl;
	this->m_EmpNum = num;

	// 开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 将文件中的数据存到数组中
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号: " << this->m_EmpArray[i]->m_ID
			<< "姓名：" << this->m_EmpArray[i]->m_Name
			<< "部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}

}

// 展示菜单
void WorkerManger::Show_Menu()
{
	cout << "*******************************************" << endl;
	cout << "*******  欢迎使用职工管理系统 *************" << endl;
	cout << "*******  0 退出管理程序 *******************" << endl;
	cout << "*******  1 增加职工信息 *******************" << endl;
	cout << "*******  2 显示职工信息 *******************" << endl;
	cout << "*******  3 删除离职职工 *******************" << endl;
	cout << "*******  4 修改职工信息 *******************" << endl;
	cout << "*******  5 查找职工信息 *******************" << endl;
	cout << "*******  6 按照编号排序 *******************" << endl;
	cout << "*******  7 清空所有文档********************" << endl;
	cout << "*********************************" << endl;
}

// 退出系统
void WorkerManger::ExitSystem()
{
	cout << "欢迎下次继续使用" << endl;
	system("pause");
	exit(0);
}


// 添加职工信息
void WorkerManger::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];
		// 将原来空间中的数据 拷贝到新空间中
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个职工岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employer(id, name, dSelect);
				break;
			case 2:
				worker = new Manger(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			// 将创建职工职责 保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		// 释放原有空间
		delete[] this->m_EmpArray;
		// 更改新空间的指向
		this->m_EmpArray = newSpace;
		// 更新职工人数
		this->m_EmpNum = newSize;
		// 职工不为空的标志
		this->m_FileIsEmpty = false;
		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
		// 保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	// 按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}
// 统计人数
int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		// 统计人数变量
		num++;
	}
	return num;
}


// 保存文件
void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 用写文件方式打开文件
	// 将数据写入文件
	for (int i = 0;i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " " << endl;
	}
	// 关闭文件
	ofs.close();
}

void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int index = 0;
	// id name dId在读取时保存 并传递给相关对象
	while (ifs>>id && ifs>>name && ifs>>dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employer(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manger(id, name, dID);
		}
		else if (dID == 3)
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
// 显示职工
void WorkerManger::Show_Emp()
{
	// 判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	// 按任意键清
	system("pause");
	system("cls");
}
// 删除职工
void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		// 根据职工编号删除职工
		cout << "请输入要删除的职工编号： " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				// 数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;// 更新数组中记录人员个数
			// 数据同步更新到文件中
			this->save();
		}
		else
		{
			cout << "未找到，删除失败" << endl;
		}
	}
	system("pause");
	system("cls");
}



// 判断职工是否存在
int WorkerManger::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 修改
void WorkerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		// 修改职工
		cout << "请输入要修改的职工编号： " << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查找到：" << id << "号职工，请输入新职工号: " << endl;
			cin >> newID;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新的岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employer(newID, newName, dSelect);
				break;
			case 2:
				worker = new Manger(newID, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newID, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			// 数据同步更新到文件中
			this->save();
		}
		else
		{
			cout << "未找到，修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

// 查找
void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找 " << endl;
		cout << "2、按职工姓名查找 " << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// 按编号查
			int id;
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			// 按姓名查
			// 按编号查
			string name;
			cout << "请输入要查找的职工姓名:" << endl;
			cin >> name;

			// 加入判断是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，该职工信息如下:" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败" << endl;
			}
				
		}
	}
	system("pause");
	system("cls");
}
// 排序
void WorkerManger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "选择排序方式：" << endl;
		cout << "1、按职工号进行升序排列" << endl;
		cout << "2、按职工号进行降序排列" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minMax = i;// 声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					// 升序
					if (this->m_EmpArray[minMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minMax = j;
					}

				}
				else if (select == 2)
				{
					// 降序
					if (this->m_EmpArray[minMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minMax = j;
					}
				}
			}
			if (i != minMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minMax];
				this->m_EmpArray[minMax] = temp;
			}
		}
	}
	cout << "排序成功,排序后的结果为：" << endl;
	this->save();
	this->Show_Emp();

}

// 清空文件
void WorkerManger::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定清空" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc); // 删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_FileIsEmpty; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			// 删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}