# include <iostream>
using namespace std;
# include "swap.h"

void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "输出交换后的输出num1=" << num1 << endl;
	cout << "输出交换后的输出num2=" << num2 << endl;
}
