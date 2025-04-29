#pragma once

#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:
    String(const char* cstr = 0);// ���캯��
    String(const String& str);// �������캯��
    String& operator=(const String& str);//������ֵ ֻҪ����ʹ�õ���ָ�� һ��Ҫ��д�������캯���Ϳ�����ֵ
    ~String();// ��������
    char* get_c_str() const { return m_data; }
private:
    char* m_data;// ����ָ�� ��̬�����ַ����ռ��С
};

#include <cstring>

inline
String::String(const char* cstr)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];// �ַ���������һ��0 �ʻ���+1�Ŀռ�洢0
        strcpy(m_data, cstr);// ��������ַ����ռ䲻Ϊ0
    }
    else {
        m_data = new char[1];//����һ����ָ�� ����һ���ַ���С�Ŀռ�
        *m_data = '\0';// �����0 0��ʾ���ַ�������
    }
}

inline
String::~String()
{
    delete[] m_data;// �ͷŶ�̬����Ŀռ�
}

inline
String& String::operator=(const String& str)
{
    if (this == &str)// ����Ƿ������Ҹ�ֵ s2=s1 ��������strָ��s1 
        return *this;// ���s2��s1�Ƿ�ָ��ͬһ���ַ
    // �����������Ҹ�ֵ�����ܻᱨ�� ��a = aʱ��ָ��ͬһ���ַ 
    // ����ɾ���ڴ�ռ� ֱ�Ӱѹ�ָͬ���ֵ��ɾ����

    delete[] m_data;// ��s1��ֵ��ֵ��s2 ���ͷ�s2���ڴ�ռ�
    m_data = new char[strlen(str.m_data) + 1];// ������s2���ڴ�ռ���s1һ����
    strcpy(m_data, str.m_data);// ��s1�����ݸ�ֵ��s2
    return *this;// ����������ֵ�������Ҫ
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
    os << str.get_c_str();// �������ָ����ָ����ַ����� ��Ϊ��<<�������������
    return os;
}

#endif
