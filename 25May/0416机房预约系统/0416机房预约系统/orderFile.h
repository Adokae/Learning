#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>


/*
预约类的实现：使用map容器嵌套map容器
map<int, map<string, string>>：
int类型表示文件中第几条记录
map<string, string>表示该条记录所对应的信息
*/

class OrderFile
{
public:
	// 构造函数
	OrderFile();

	// 更新预约记录
	void updateOrder();

	// 预约条数
	int m_Size;

	// 记录所有预约信息的容器
	map<int, map<string, string>> m_orderData;
};