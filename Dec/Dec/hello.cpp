#include <iostream>
using namespace std;

int main()
{
   // cout << "Hello, World!" << endl;
    int a1 = 0;
    int b1 = a1++ * 10;
    cout << a1 << endl;
    cout << b1 << endl;
    //后置递增先计算表达式，在对变量加1
    // 故上述b1为0
    int a2 = 0;
    int b2 = ++a2 * 10;
    cout << a2 << endl;
    cout << b2 << endl;
    // 前置递增先对变量加1，在计算表达式
    // 故上述b2为10
    /*  ！-非   &&-与   ||-或 */
    cout << !a1 << endl;
    cout << (a1 && a2) << endl;
    cout << (a1 || a2) << endl;
    return 0;
}