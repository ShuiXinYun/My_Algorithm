/*
�������������㷨��������c++������������� 
Week4
�����Լ������������
���������++���Լ������--��ǰ��/����֮�֣�Ϊ�����������ص���ǰ ����������Ǻ����������C++�涨�� 
ǰ���������ΪһԪ���������
�����������Ϊ��Ԫ��������أ���дһ��û�õĲ���
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
		//���������������
		friend ostream & operator << (ostream & output, const Complex &cp);
		//ǰ��������������� 
		Complex & operator ++ (); //��Ϊ��Ա��������
//		friend Complex & operator ++ (Complex & cp); //��Ϊȫ�ֺ������� 
		//������������� 
		Complex & operator -- (int);
//		friend Complex & operator -- (Complex & cp, int);//��Ϊȫ�ֺ������� 
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
