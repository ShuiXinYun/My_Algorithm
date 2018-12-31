/*
北大程序设计与算法（三）：c++面向对象程序设计 
Week4
自增自减运算符的重载
自增运算符++、自减运算符--有前置/后置之分，为了区分所重载的是前 置运算符还是后置运算符，C++规定： 
前置运算符作为一元运算符重载
后置运算符作为二元运算符重载，多写一个没用的参数
*/

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
		//流插入运算符重载
		friend ostream & operator << (ostream & output, const Complex &cp);
		//前置自增运算符重载 
		Complex & operator ++ (); //作为成员函数重载
//		friend Complex & operator ++ (Complex & cp); //作为全局函数重载 
		//后置运算符重载 
		Complex & operator -- (int);
//		friend Complex & operator -- (Complex & cp, int);//作为全局函数重载 
};

Complex & Complex::operator ++()
{
	this->real +=1;
	return *this;
} 
 
//Complex & operator ++ (Complex & cp)
//{
//	cp.real +=1;
//	return cp;
//}

Complex & Complex::operator --(int)
{
	Complex c_tmp(*this);
	this->real -=1;
	return c_tmp;
}

//Complex & operator -- (Complex & cp, int)
//{
//	Complex c_tmp(cp);
//	cp.real -=1;
//	return c_tmp;
//}

ostream & operator << (ostream & output, const Complex &cp)
{
	output<<cp.real<<"+"<<cp.imag<<"i"<<endl;
	return output;
}

void test()
{
	Complex c1(3.6, 6.3);
	cout<<"c1: "<<c1;
	cout<<"++c1: "<<++c1;
	cout<<c1--;
	cout<<"after: "<<c1;
}
/*
c1: 3.6+6.3i
++c1: 4.6+6.3i
4.6+6.3i
after: 3.6+6.3i
*/

int main()
{
	test();
	return 0;
}
