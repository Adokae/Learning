# include <iostream>
using namespace std;
/*
��ת��䣺��������ѡ��ṹ��ѭ���ṹ
break��䣺
1��������switch��������У���������ֹcase������switch
2��������ѭ������У�������������ǰ��ѭ�����
3��������Ƕ��ѭ���У���������ڲ�ѭ�����
*/
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
		if (i == 5)
		{
			break;
		}
	}
	system("pause");
	return 0;

}