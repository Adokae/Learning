# include <iostream>
using namespace std;
# include <fstream>
# include <string>
/*
程序运行时产生的数据都属于临时数据，程序一旦结束数据都会被释放
通过文件将数据持久化
文件操作：
1 对文件操作需要包含头文件<fstream>

文件类型分两类：
1 文件文件：文件以文本的ASCII码形式存储到计算机中
2 二进制文件：文件以文本的二进制形式存储到计算机中

操作文件三大类：
1 ofstream:写操作
2 ifstream:读操作
2 fstream：读写操作

文件打开方式：
ios::in 为读文件而打开文件
ios::out 为写文件而打开文件


*/

// 文本文件操作 写文件
void test1()
{
	//1 添加头文件

	//2 创建流对象
	ofstream ofs;
	//3 指定打开方式
	ofs.open("test.txt", ios::out);
	//4 写内容
	ofs << "name:小明" << endl;
	ofs << "age:18" << endl;
	ofs << "sex:男" << endl;
	//5 关闭文件
	ofs.close();
}

// 文本文件操作 读文件
void test2()
{
	//1 添加头文件

	//2 创建流对象
	ifstream ifs;
	//3 指定打开方式 判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4 读取数据
	// 第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/

	//// 第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// 第三种
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/

	//// 第四种 EOF 文件尾部标志 end of file
	char c;
	while ((c = ifs.get() )!= EOF)
	{
		cout << c ;
	}

	//5 关闭文件
	ifs.close();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
