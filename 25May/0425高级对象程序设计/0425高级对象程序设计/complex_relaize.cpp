#include <iostream>
using namespace std;
#include "complex.h"

inline complex& __doapl(complex * ths, const complex& r){
	ths->re += r.re;
	ths->im += r.im;
	return *ths;

}


// 重写<< cout的类型是ostream 在使用时会不断改变
ostream& operator << (ostream& os, const complex& x) {
	return os << '(' << real(x) << imag(x) << ')';
}

// += 左边的值是不变的-》加const 右边值本来就存在-》返回引用
inline complex& complex::operator += (const complex& r) {
	return __doapl(this, r);
}