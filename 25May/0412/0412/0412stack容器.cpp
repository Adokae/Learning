# include <iostream>
using namespace std;
#include <stack>
/*
stack������
stack������һ���Ƚ���������ݽṹ��ֻ��һ������
�����������Ϊ

ջ�����ж������Ƿ�Ϊ��
ջ�����ж�Ԫ�ظ���

ջ�н������ݳ�Ϊ��ջ-push
ջ�е������ݳ�Ϊ��ջ-pop

ջ�г��ýӿڣ�
���캯����
1 stack<T> stk;stack����ģ����ʵ�� stack�����Ĭ�Ϲ�����ʽ
2 stack(const stack &stk); �������캯��

��ֵ����
1 stack& operator=(const stack &stk)�� ���صȺŲ�����

���ݴ�ȡ��
1 push(elem)����ջ�����Ԫ��
2 pop();��ջ���Ƴ���һ��Ԫ��
3 top();����ջ��Ԫ��

��С������
1 empty();�ж�ջ���Ƿ�Ϊ��
2 size()������ջ�Ĵ�С
*/

void test1() {
	stack<int> s;
	// ��ջ����
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	// ֻҪջ��Ϊ�� �鿴ջ�� ����ִ�г�ջ����
	while (!s.empty()) {
		// �鿴ջ��Ԫ��
		cout << "ջ��Ԫ�أ�" << s.top() << endl;

		// ��ջ����
		s.pop();
	}
	cout << "ջ�Ĵ�С��" << s.size() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}
