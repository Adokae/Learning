# include <iostream>
using namespace std;
/*
continue��䣺��ѭ������У���������ѭ����������δִ�е���䣬
����ִ����һ��ѭ��
����ɸѡ������ִ�е��˾Ͳ�������ִ�У�ִ����һ��ѭ��
*/
int main()
{
	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		printf("%d\n", i);
	}
	system("pause");
	return 0;

}