# include <iostream>
using namespace std;
# include <fstream>
# include <string>
/*
��������ʱ���������ݶ�������ʱ���ݣ�����һ���������ݶ��ᱻ�ͷ�
ͨ���ļ������ݳ־û�
�ļ�������
1 ���ļ�������Ҫ����ͷ�ļ�<fstream>

�ļ����ͷ����ࣺ
1 �ļ��ļ����ļ����ı���ASCII����ʽ�洢���������
2 �������ļ����ļ����ı��Ķ�������ʽ�洢���������

�����ļ������ࣺ
1 ofstream:д����
2 ifstream:������
2 fstream����д����

�ļ��򿪷�ʽ��
ios::in Ϊ���ļ������ļ�
ios::out Ϊд�ļ������ļ�


*/

// �ı��ļ����� д�ļ�
void test1()
{
	//1 ���ͷ�ļ�

	//2 ����������
	ofstream ofs;
	//3 ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);
	//4 д����
	ofs << "name:С��" << endl;
	ofs << "age:18" << endl;
	ofs << "sex:��" << endl;
	//5 �ر��ļ�
	ofs.close();
}

// �ı��ļ����� ���ļ�
void test2()
{
	//1 ���ͷ�ļ�

	//2 ����������
	ifstream ifs;
	//3 ָ���򿪷�ʽ �ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4 ��ȡ����
	// ��һ��
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/

	//// �ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// ������
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/

	//// ������ EOF �ļ�β����־ end of file
	char c;
	while ((c = ifs.get() )!= EOF)
	{
		cout << c ;
	}

	//5 �ر��ļ�
	ifs.close();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}
