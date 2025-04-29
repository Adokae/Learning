#pragma once
#include <iostream>
using namespace std;
/*
学生、老师、管理员三种身份有其特性，也有共性，将三种身份
抽象为一个身份基类
*/
class Identity
{
public:
	// 操作菜单 纯虚函数
	virtual void operMenu() = 0;

	string m_Name;// 用户名
	string m_Pwd;// 密码
};


