#include <iostream>
using namespace std;

int main()
{
   // cout << "Hello, World!" << endl;
    int a1 = 0;
    int b1 = a1++ * 10;
    cout << a1 << endl;
    cout << b1 << endl;
    //���õ����ȼ�����ʽ���ڶԱ�����1
    // ������b1Ϊ0
    int a2 = 0;
    int b2 = ++a2 * 10;
    cout << a2 << endl;
    cout << b2 << endl;
    // ǰ�õ����ȶԱ�����1���ڼ�����ʽ
    // ������b2Ϊ10
    /*  ��-��   &&-��   ||-�� */
    cout << !a1 << endl;
    cout << (a1 && a2) << endl;
    cout << (a1 || a2) << endl;
    return 0;
}