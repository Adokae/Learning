# include <iostream>
using namespace std;
# include <string>

/*
�ṹ��Ļ������
�û��Զ�����������ͣ������û��洢��ͬ����������
ʵ������һ���������͵ļ���
�﷨�� struct �ṹ���� {�ṹ���Ա�б�}��

ͨ���ṹ�崴�������ķ�ʽ���������֣�
1 struct �ṹ���� ������
2 struct �ṹ���� ������ = {��Ա1ֵ����Ա2ֵ��...}
3 ����ṹ��ʱ˳�㴴������



*/

//ʵ����
//����ѧ���������� ѧ���������� ���� ����
struct Student
{
	// ��Ա�б�

	// ����
	string name;
	// ����
	int age;
	//����
	int score;
} s3;  // ˳�㴴��һ���ṹ�����



int main()
{
	//ͨ���������ʹ�������ѧ��
	//��ʽ1
	struct Student s1;  // ����ʱ���ؼ��ֿ���ʡ��
	// ��s1���Ը�ֵ��ͨ��.(��)���ʽṹ������е�����
	s1.name = "����";
	s1.age = 18;
	s1.score = 100;
	cout << "s1��������ݣ�" << s1.name << s1.age << s1.score << endl;

	//��ʽ2
	struct Student s2 = {"����", 19, 80};
	cout << "s2��������ݣ�" << s2.name << s2.age << s2.score << endl;
	


	// ��ʽ3 �����������ṹ��
	s3.name = "����";
	s3.age = 30;
	s3.score = 99;
	cout << "s3��������ݣ�" << s3.name << s3.age << s3.score << endl;
	
	
	system("pause");
	return 0;
}
