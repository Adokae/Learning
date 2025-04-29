#include "orderFile.h"


// 构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string statue;
	this->m_Size = 0; // 记录条数初始化为0

	while (ifs >> date && ifs >> interval && ifs >> 
		stuId && ifs >> stuName && ifs >> roomId && ifs >> statue)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/
		string key;
		string value;
		string arr[6] = {date, interval, stuId, stuName, roomId, statue};

		map<string, string>m;

		int pos;
		for (int i = 0; i < 6; i++)
		{
			pos = arr[i].find(":");
			if (pos != -1)
			{
				key = arr[i].substr(0, pos);
				value = arr[i].substr(pos + 1, arr[i].size() - pos + 1);
				/*cout << "key = " << key << endl;
				cout << "value = " << value << endl;*/
				m.insert(make_pair(key, value));
			}
		}
		// 将小map容器放入到大容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

		// 日期
		//pos = date.find(":");
		//if (pos != -1)
		//{
		//	key = date.substr(0, pos);
		//	value = date.substr(pos + 1, date.size() - pos + 1);
		///*	cout << "key = " << key << endl;
		//	cout << "value = " << value << endl;*/
		//	m.insert(make_pair(key, value));
		//}
		//
		//// 间隔
		//pos = interval.find(":");
		//if (pos != -1)
		//{
		//	key = interval.substr(0, pos);
		//	value = interval.substr(pos + 1, interval.size() - pos + 1);
		//	m.insert(make_pair(key, value));
		//}
		//
		//// ID
		//pos = stuId.find(":");
		//if (pos != -1)
		//{
		//	key = stuId.substr(0, pos);
		//	value = stuId.substr(pos + 1, stuId.size() - pos + 1);
		//	m.insert(make_pair(key, value));
		//}

		//// 姓名
		//pos = stuName.find(":");
		//if (pos != -1)
		//{
		//	key = stuName.substr(0, pos);
		//	value = stuName.substr(pos + 1, stuName.size() - pos + 1);
		//	cout << "key = " << key << endl;
		//	cout << "value = " << value << endl;
		//	m.insert(make_pair(key, value));
		//}

		//// 房间ID号
		//pos = roomId.find(":");
		//if (pos != -1)
		//{
		//	key = roomId.substr(0, pos);
		//	value = roomId.substr(pos + 1, roomId.size() - pos + 1);
		//	m.insert(make_pair(key, value));
		//}

		//// 状态
		//pos = status.find(":");
		//if (pos != -1)
		//{
		//	key = status.substr(0, pos);
		//	value = status.substr(pos + 1, status.size() - pos + 1);
		//	m.insert(make_pair(key, value));
		//}
	}
	ifs.close();
	// 测试最外层map容器中的元素值
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "条数为： " << it->first << endl;
	//	for(map<string,string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key = " << mit->first << " value = " << mit->second << endl;
	//	}
	//	cout << endl;
	//}

}

// 更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return; // 预约记录为0
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "statue:" << this->m_orderData[i]["statue"] <<endl;
	}
	ofs.close();
}