#include "string.h"
#include <iostream>

using namespace std;
/*
带指针的拷贝需要自己重写拷贝构造函数

*/

int main()
{
    String s1("hello");
    String s2("world");

    String s3(s2);
    cout << s3 << endl;

    s3 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
}
