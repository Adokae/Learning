# include <iostream>
using namespace std;

/*
�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
����Ȩ�������֣�
1 public ����Ȩ�� ���ڿ��Է��� ����Ҳ���Է���
2 protected ����Ȩ�� ���ڿ��Է��� ���ⲻ���Է��� 
������Է��ʸ���ı�������
3 private ˽��Ȩ�� ���ڿ��Է��� ���ⲻ���Է���
���಻���Է��ʸ����˽������
*/

class Person
{
public:
	string Name;
protected:
	string Car;
private:
	int Password;
public:
	void func()
	{
		Name = "����";
		Car = "С����";
		Password = 12345;
	}
};
int main()
{
	Person p1;
	p1.Name = "����";
	// ˽��Ȩ��/����Ȩ�������ⲻ���Է���
	// ����ʾ��
	//p1.Car = 145;
	system("pause");

	return 0;
}
