# include <iostream>
using namespace std;
# include "通讯录管理系统.h"
# include <string>
# define Max 1000
/*
实现通讯录管理系统，要实现的功能如下：
1 添加联系人：在通讯录中添加新人，
信息包括（姓名、性别、年龄、联系电话、家庭地址），最多包括1000人
2 显示联系人：显示通讯录中所有联系人的信息
3 删除联系人：按照姓名删除指定联系人
4 查找联系人：按照姓名查找指定联系人
5 修改联系人：根据姓名重新修改指定联系人
6 清空联系人：清空通讯录中所有信息
7 退出通讯录：推出当前使用的通讯录
*/

/*
实现步骤：
1 菜单显示 展示用户选择功能的界面 使用showMenu()函数
2 用户不同选择，进入不同功能，使用switch分支结构
3 添加联系人：设计联系人结构体 设计通讯录结构体 main函数中创建通讯录
4 显示联系人:通讯录中没有人，提示记录为空；否则显示通讯录中信息
5 删除联系人：先检测联系人是否存在，在删除
6 查找联系人：先判断所要查找的人是否存在，按照姓名查找指定联系人信息
7 修改联系人：先判断所要查找的人是否存在，存在则对其进行相应修改
8 清空联系人：直接将记录人数置为0，逻辑清空
*/

// 联系人结构体
struct Person
{
	string m_Name;
	int m_Sex; // 1 男 2 女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

// 通讯录结构体
struct AddressBooks
{
	// 通讯录中保存的联系人数组
	struct Person personArray[Max];
	// 通讯录中当前记录联系人的个数
	int m_Size;
};

void addPerson(AddressBooks* abs)
{
	// 判断通讯录中现有成员个数
	if (abs->m_Size == Max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入性别有误，请重新输入" << endl;
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (0 <= age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入年龄有误，请重新输入" << endl;
		}
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		// 添加一个人的信息后，通讯录人数加1
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");// 清屏操作
	}
}

// 2 显示所有联系人
void showPerson(AddressBooks* abs)
{
	// 判断通讯录中人数
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空，无法显示" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//3 检测联系人是否存在 若存在 返回联系人在数组中的具体未知
// 若不存在返回-1 输入通讯录和要找到的人名
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1; // 未找到
}

// 4 删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "输入要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		// 进行删除操作，实际使用后面的人覆盖要删除的人
		// 最终的总人数减1
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 4 查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "请输入要查找的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男":"女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


// 5 修改指定联系人信息
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入修改后的联系人姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "请输入修改后的联系人的性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入性别有误，请重新输入" << endl;
		}
		int age;
		cout << "请输入修改后的联系人年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		string phone;
		cout << "请输入修改后的联系人电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		string address;
		cout << "请输入修改后的联系人地址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 6 清空联系人
void cleanPerson(AddressBooks * abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录结构体变量
	AddressBooks abs;
	// 初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; // 用户选择的变量

	while (true)
	{
		showMenu();
		cout << "输入用户所要选择的变量：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			// 添加联系人
			addPerson(&abs); // 利用地址传递修改实参值
			break;
		case 2:
			// 显示联系人
			showPerson(&abs);
			break;
		case 3:
			// 删除联系人
			deletePerson(&abs);
			break;
		case 4:
			// 查找联系人
			findPerson(&abs);
			break;
		case 5:
			// 修改联系人
			modifyPerson(&abs);
			break;
		case 6:
			// 清空联系人
			cleanPerson(&abs);
			break;
		case 0:
			// 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	/*system("pause");
	return 0;*/
}
