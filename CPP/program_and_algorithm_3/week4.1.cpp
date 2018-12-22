/* 
�������������㷨��������c++������������� 
Week4
���������
���� + -ʵ�ָ����Ӽ� 
���� + -Ϊ��Ԫ������֧�����ҼӼ� 
���� = ʵ��ʵ����ֵ����������ע�������ʼ����������ʹ�õ��Ĺ��캯�������� 
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
		// - ��������� 
		Complex operator - (double r); 
		friend Complex operator - (double r, const Complex &cp);
		Complex operator - (const Complex & cp); 
		// + ��������� 
		Complex operator + (double r); 
		friend Complex operator + (double r, const Complex &cp);
		Complex operator + (const Complex & cp);
		// ��ֵ��������� 
		Complex operator = (const double real);
};

// - ���������ʵ�� 
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

// + ���������ʵ�� 
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

// = ���������ʵ�� 
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
	cout<<"sizeof Complex: "<<sizeof(Complex)<<endl; //16�ֽ�, ����double 
	Complex c1 = Complex(1.1, 2.2); // ����double�����Ĺ��캯�� 
	Complex c2 = Complex(3.3, 4.4);
	printf("c1: ");
	print_Complex(c1); 
	printf("c2: ");
	print_Complex(c2);
	Complex c3 = c1 + c2; //Ĭ�ϸ��ƹ��캯�� 
	printf("c1 + c2: ");
	print_Complex(c3);
	Complex c4 = c2 - c1 + c3; 
	printf("c2-c1+c3: ");
	print_Complex(c4);
	Complex c5(5.5); //һ��double�����Ĺ��캯�� 
	Complex c6; //Ĭ�Ϲ��캯�� 
	c6 = 6.6; // ��ֵ��������� 
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

