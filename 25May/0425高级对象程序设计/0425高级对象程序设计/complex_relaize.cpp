#include <iostream>
using namespace std;
#include "complex.h"

inline complex& __doapl(complex * ths, const complex& r){
	ths->re += r.re;
	ths->im += r.im;
	return *ths;

}


// ��д<< cout��������ostream ��ʹ��ʱ�᲻�ϸı�
ostream& operator << (ostream& os, const complex& x) {
	return os << '(' << real(x) << imag(x) << ')';
}

// += ��ߵ�ֵ�ǲ����-����const �ұ�ֵ�����ʹ���-����������
inline complex& complex::operator += (const complex& r) {
	return __doapl(this, r);
}