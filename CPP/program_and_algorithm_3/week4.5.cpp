/*
�������������㷨��������c++������������� 
Week4
�����������������ȡ�����������
�ٶ�c��Complex������Ķ�������ϣ��д"cout << c;", ������"a+bi"����ʽ���c��ֵ,
д"cin>>c;"�����ܴӼ��̽���"a+bi"��ʽ������, ����ʹ��c.real = a,c.imag = b.
����ת�����������, Complex����ǿ��ת��Ϊdouble���͵�ʵ�� 
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
		//���������������
		friend ostream & operator << (ostream & output, const Complex &cp);
		//����ȡ��������� 
		friend istream & operator >> (istream & input, const Complex &cp);
		//ǿ������ת�������������, ���������������� 
		operator double(); 
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

//��������������� 
ostream & operator << (ostream & output, const Complex &cp)
{
	output<<cp.real<<"+"<<cp.imag<<"i"<<endl;
	return output;
}

//����ȡ����� 
istream & operator >> (istream & input, Complex &cp)
{
	//string�෽����ʹ�� 
	string s;
	input>>s;
	int pos = s.find("+",0);
	string r_tmp = s.substr(0, pos);
	cp.real = atof(r_tmp.c_str());
	string i_tmp = s.substr(pos+1, s.length()-pos-2);
	cp.imag = atof(i_tmp.c_str());
	return input;
}

//ǿ������ת�������������, ���������������� 
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
