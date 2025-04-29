#pragma once
#ifndef __COMPLEX__// ifdef表示若未曾经定义过COMPLEX 就进入下列代码
#define __COMPLEX__
#include <cmath>

class complex;
complex& __doapl(complex* ths, const complex& r);// 前置声明
complex& __doami(complex* ths, const complex& r);
complex& __doaml(complex* ths, const complex& r);

class complex {
	// 类声明
public:
	complex(double r = 0, double i = 0) :re(r), im(i) {}
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);

	double real() const { return re; }//可改为使用模板 使用函数时 需要考虑是否使用const
	double imag() const { return im; }// const表示不改变函数中的数据内容
	//参数传递时 一般考虑传递参数的引用
	//返回值的传递 尽量考虑传递引用

private:
	// 一般将数据定义为私有类型
	double re, im;
	friend complex& __doapl(complex*, const complex&);
	friend complex& __doami(complex*, const complex&);
	friend complex& __doaml(complex*, const complex&);
};

inline complex& __doapl(complex* ths, const complex& r) {
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
inline complex& complex::operator += (const complex& r) {
	return __doapl(this, r);
}


inline complex& __doami(complex* ths, const complex& r) {
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}
inline complex& complex::operator -= (const complex& r) {
	return __doami(this, r);
}


inline complex& __doaml(complex* ths, const complex& r) {
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;
	return *ths;
}
inline complex& complex::operator *= (const complex& r) {
	return __doaml(this, r);
}


inline double imag(const complex& x) {
	return x.imag();
}


inline double real(const complex& x) {
	return x.real();
}


inline complex operator+(const complex& x, const complex& y) {
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+ (const complex& x, double y) {
	return complex(real(x) + y, imag(x));
}

inline complex operator + (double x, const complex& y) {
	return complex(x + real(y), imag(y));
}


#endif

