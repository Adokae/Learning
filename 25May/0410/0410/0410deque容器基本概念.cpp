# include <iostream>
using namespace std;
#include <deque>
/*
deque������
˫�����飬���Զ�ͷ�˽��в��롢ɾ������

deque��vector����
1 vector����ͷ������ɾ��Ч�ʵ� ������Խ�� Ч��Խ��
2 deque��Զ��� ��ͷ���Ĳ���ɾ���ٶȱ�vector��
3 vector����Ԫ��ʱ���ٶȻ��deque�� ��������ڲ�ʵ���й�

deque�ڲ�����ԭ��
	deque�ڲ���һ���п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
	�п�����ά������ÿ���������ĵ�ַ��ʹʹ��dequeʱ��һƬ�������ڴ�ռ�

deque�����ĵ�����֧��������ʵ�

deque���캯����deque��������
������
1 deque<T>deqT; Ĭ�Ϲ�����ʽ
2 deque(beg, end);���캯����[beg,end)�����е�Ԫ�ؿ���������
3 deque(n,elem);����������n��elem����������
4 deque(const deque &deq); �������캯��
*/

// ��const��ֹ�������е�ֵ�����޸�
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		//*it = 100;
		cout << *it << " ";
	}
	cout << endl;
}


void test1() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	//deque<int>d4(d3);
	deque<int>d4 = d3;
	printDeque(d4);
}
int main()
{
	test1();
	system("pause");

	return 0;
}
