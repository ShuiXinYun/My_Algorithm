/*
北大程序设计与算法（三）：c++面向对象程序设计 
Week4
流插入运算符和流提取运算符的重载
假定c是Complex复数类的对象，现在希望写"cout << c;", 就能以"a+bi"的形式输出c的值,
写"cin>>c;"，就能从键盘接受"a+bi"形式的输入, 并且使得c.real = a,c.imag = b.
类型转换运算符重载, Complex类型强制转换为double类型的实现 
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

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
		//流插入运算符重载
		friend ostream & operator << (ostream & output, const Complex &cp);
		//流提取运算符重载 
		friend istream & operator >> (istream & input, const Complex &cp);
		//强制类型转换运算符的重载, 无需声明返回类型 
		operator double(); 
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

//流插入运算符重载 
ostream & operator << (ostream & output, const Complex &cp)
{
	output<<cp.real<<"+"<<cp.imag<<"i"<<endl;
	return output;
}

//流提取运算符 
istream & operator >> (istream & input, Complex &cp)
{
	//string类方法的使用 
	string s;
	input>>s;
	int pos = s.find("+",0);
	string r_tmp = s.substr(0, pos);
	cp.real = atof(r_tmp.c_str());
	string i_tmp = s.substr(pos+1, s.length()-pos-2);
	cp.imag = atof(i_tmp.c_str());
	return input;
}

//强制类型转换运算符的重载, 无需声明返回类型 
Complex::operator double()
{
	return this->real; 
} 

void test_Complex()
{
	Complex c1, c2;
	cout<<"input c1:\n";
	cin>>c1;
	cout<<"input c2:\n";
	cin>>c2;
	cout<<"c1+c2:\n";
	cout<<c1+c2; 
	cout<<"c1+c2 to double: ";
	cout<<(double)(c1+c2)<<endl;
}
/*
input c1:
2+3.6i
input c2:
3+6.6i
c1+c2:
5+10.2i
c1+c2 to double: 5
*/

int main()
{
	test_Complex();
	return 0;
}
