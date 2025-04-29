#pragma once

#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:
    String(const char* cstr = 0);// 构造函数
    String(const String& str);// 拷贝构造函数
    String& operator=(const String& str);//拷贝赋值 只要类中使用到了指针 一定要重写拷贝构造函数和拷贝赋值
    ~String();// 析构函数
    char* get_c_str() const { return m_data; }
private:
    char* m_data;// 创建指针 动态调整字符串空间大小
};

#include <cstring>

inline
String::String(const char* cstr)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];// 字符串后面有一个0 故还需+1的空间存储0
        strcpy(m_data, cstr);// 若传入的字符串空间不为0
    }
    else {
        m_data = new char[1];//传递一个空指针 开辟一个字符大小的空间
        *m_data = '\0';// 后面放0 0表示该字符串结束
    }
}

inline
String::~String()
{
    delete[] m_data;// 释放动态分配的空间
}

inline
String& String::operator=(const String& str)
{
    if (this == &str)// 检测是否是自我赋值 s2=s1 传进来的str指向s1 
        return *this;// 检测s2与s1是否指向同一块地址
    // 若不考虑自我赋值，可能会报错 但a = a时，指向同一块地址 
    // 下面删除内存空间 直接把共同指向的值给删除了

    delete[] m_data;// 把s1的值赋值给s2 先释放s2的内存空间
    m_data = new char[strlen(str.m_data) + 1];// 创建出s2的内存空间与s1一样大
    strcpy(m_data, str.m_data);// 把s1的内容赋值给s2
    return *this;// 出现连续赋值的情况需要
}

inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_str();// 输出的是指针所指向的字符序列 因为对<<运算符进行重载
    return os;
}

#endif
