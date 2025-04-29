# include <iostream>
using namespace std;
#include <deque>
/*
deque�Ĳ����ɾ������

����ԭ�ͣ�
���˲������
1 push_back(elem) ; ������β�����һ������
2 push_front(elem); ������ͷ������һ������
3 pop_back();ɾ���������һ������
4 pop_front();ɾ��������һ������

ָ��λ�ò�����
1 insert(pos, elem);��posλ�ò���һ��elemԪ�صĿ��� ���������ݵ�λ��
2 insert(pos, n, elem);��posλ�ò���n��elemԪ��,�޷���ֵ
3 inset(pos, beg, end);��posλ�ò���[beg, end)�����Ԫ��,�޷���ֵ
4 clear();�����������������
5 erase(beg,end); ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
6 erase(pos);ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
*/

void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// ���˲���
void test1() {
	deque<int>d1;
	// β��
	d1.push_back(10);
	d1.push_back(20);

	// ͷ������
	d1.push_front(5);
	d1.push_front(1);

	printDeque(d1);

	// βɾ
	d1.pop_back();
	printDeque(d1);

	// ͷɾ
	d1.pop_front();
	printDeque(d1);
}


void test2() {
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_back(40);
	printDeque(d2);

	// insert����
	d2.insert(d2.begin(), 1000);
	printDeque(d2);

	d2.insert(d2.begin(), 2, 100);
	printDeque(d2);

	// ��������в���
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);
}


void test3() {
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);

	// ɾ��
	//d3.erase(d3.begin());// ɾ����Ԫ��
	deque<int>::iterator it = d3.begin();
	it++;
	d3.erase(it);
	printDeque(d3);

	// ���������ɾ��
	d3.erase(d3.begin(), d3.end());
	//d3.clear();
	printDeque(d3);
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");

	return 0;
}
