/* 
北大程序设计与算法（三）：c++面向对象程序设计 
Week4
运算符重载
重载 + -实现复数加减 
重载 + -为友元函数以支持左右加减 
重载 = 实现实数赋值给复数对象，注意其与初始化复数对象使用到的构造函数的区别 
*/
#include<cstdio>
#include<iostream>
using namespace std;

class Complex
{
	public:
		double real;
		double imag;
		Complex()
		{
			real = 0.0;
			imag = 0.0;
		}
		Complex(double r):real(r) {}
		Complex(double r, double i):real(r), imag(i) {}
		~Complex(){}
		friend void print_Complex(const Complex & cp);
		// - 运算符重载 
		Complex operator - (double r); 
		friend Complex operator - (double r, const Complex &cp);
		Complex operator - (const Complex & cp); 
		// + 运算符重载 
		Complex operator + (double r); 
		friend Complex operator + (double r, const Complex &cp);
		Complex operator + (const Complex & cp);
		// 赋值运算符重载 
		Complex operator = (const double real);
};

// - 运算符重载实现 
Complex Complex::operator - (double r)
{
	Complex c;
	c.real = this->real -r;
	c.imag = this->imag;
	return c;
}

Complex operator - (double r, const Complex & cp)
{
	Complex c;
	c.real = r - cp.real;
	c.imag = -cp.imag;
	return c;
}

Complex Complex::operator - (const Complex & cp)
{
	Complex c;
	c.real = this->real - cp.real;
	c.imag = this->imag - cp.imag;
	return c;
}

// + 运算符重载实现 
Complex Complex::operator + (double r)
{
	Complex c;
	c.real = this->real + r;
	c.imag = this->imag;
	return c; 
} 

Complex operator + (double r, const Complex & cp)
{
	Complex c;
	c.real = r + cp.real;
	c.imag = cp.imag;
	return c; 
} 

Complex Complex::operator + (const Complex & cp)
{
	Complex c;
	c.real = this->real + cp.real;
	c.imag = this->imag + cp.imag;
	return c; 
} 

// = 运算符重载实现 
Complex Complex::operator = (double real)
{
	this->real = real;
	return *this;
}

void print_Complex(const Complex & cp)
{
	if(cp.imag>=0)
		printf("%.1lf+%.1lfi\n", cp.real, cp.imag);
	else
		printf("%.1lf%.1lfi\n", cp.real, cp.imag);
}

void test_operator()
{
	cout<<"sizeof Complex: "<<sizeof(Complex)<<endl; //16字节, 两个double 
	Complex c1 = Complex(1.1, 2.2); // 两个double参数的构造函数 
	Complex c2 = Complex(3.3, 4.4);
	printf("c1: ");
	print_Complex(c1); 
	printf("c2: ");
	print_Complex(c2);
	Complex c3 = c1 + c2; //默认复制构造函数 
	printf("c1 + c2: ");
	print_Complex(c3);
	Complex c4 = c2 - c1 + c3; 
	printf("c2-c1+c3: ");
	print_Complex(c4);
	Complex c5(5.5); //一个double参数的构造函数 
	Complex c6; //默认构造函数 
	c6 = 6.6; // 赋值运算符重载 
	Complex c7 = c1 + 1; 
	printf("c1+1: ");
	print_Complex(c7);
	Complex c8 = 1 + c1;
	printf("1+c1: ");
	print_Complex(c8);
	Complex c9 = c1 - 1;
	printf("c1-1: ");
	print_Complex(c9);
	Complex c10 = 1 - c1;
	printf("1-c1: ");
	print_Complex(c10);
}

int main()
{
	test_operator();
	return 0;
}

