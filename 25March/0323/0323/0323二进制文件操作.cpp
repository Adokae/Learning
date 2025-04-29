# include <iostream>
using namespace std;
# include <fstream>
/*
以二进制方式对文件进行读写操作：
打开方式指定为：ios::binary

写文件主要利用流对象调用成员函数write
函数原型：ostream& write(const char * buffer, int len)

读文件操作：
函数原型：istream& read(char * buffer, int len)
*/

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

// 二进制文件读文件操作
void test2()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	// 读文件
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << p.m_Age << endl;
	cout << p.m_Name << endl;
	ifs.close();
}

// 二进制文件写文件操作
void test1()
{
	ofstream ofs;

	ofs.open("person.txt", ios::out | ios::binary);

	Person p = { "张三", 20 };

	ofs.write((const char*)&p, sizeof(Person));

	ofs.close();
}

int main()
{
	test2();
	//test1();
	system("pause");

	return 0;
}
