# include <iostream>
using namespace std;
# include <string>

/*
���е����Ժ���Ϊ��ͳ��Ϊ��Ա
���ԣ���Ա���� ��Ա����
��Ϊ����Ա���� ��Ա����

*/
class Student
{
public:
	string name;
	string ID;
	void assignment()
	{
		cout << "����Ҫ��ֵ��������" << endl;
		cin >> name;
		cout << "����Ҫ��ֵ��ѧ�ţ�" << endl;
		cin >> ID;
	}
	void Print()
	{
		cout << "������"<< name << endl;
		cout << "ѧ�ţ�" << ID << endl;
	}

};
int main()
{
	Student stu;
	stu.name = "����";
	stu.ID = "123";

	stu.Print();
	stu.assignment();
	stu.Print();
	system("pause");

	return 0;
}
