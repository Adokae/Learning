#pragma once
#include <iostream>
using namespace std;

class Speaker
{
public:
	string m_Name;
	double m_Score[2]; // 有选手可能进入第二轮，有两轮得分
};