# include <iostream>
using namespace std;
/*
switch���-ִ�ж�������֧���
�﷨�ṹ��
switch(���ʽ)
{
  case ���1(���ʽ�Ľ��)��ִ����䣻break;
  ...
  default:ִ����䣻break;
}

if��switch����
switch:�ж���ֻ�������ͻ��ַ��ͣ�������һ������,�ṹ������ִ��Ч�ʸ�
*/
int main()
{
	// switch���
	cout << "����Ӱ���֣�������Χ��0��10֮�䣬���������" << endl;
	int score = 0;
	cin >> score;
	switch (score)
	{
	case 10:
		cout << "�����Ӱ" << endl;
		break;
	case 7:
		cout << "�ǳ���" << endl;
		break;
	default:
		cout << "��Ƭ" << endl;
		break;
	}
	system("pause");
	return 0;
}
