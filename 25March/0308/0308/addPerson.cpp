# include <iostream>
using namespace std;

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
		}



	}

}