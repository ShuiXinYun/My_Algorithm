/*
�������������㷨��������c++������������� 
Week8
����ģ�����ģ�� 
ʹ�ú���ģ��ʵ��Map����
ʹ����ģ��ʵ��pair 
*/

#include<iostream>
using namespace std;

template<class T, class Pfunc>
void MyMap(T s, T e, T x, Pfunc func)
{
	while(s!=e)
	{
		*x = func(*s);
		++s, ++x;
	}
}

double square(double x)
{
	return x*x;
}

int main()
{
	int a[5] = {1,2,3,4,5}, c[5];
	double b[5] = {1.1,2.2,3.3,4.4,5.5}, d[5];
	MyMap(a, a+5, c, square); //MyMap(int * s,int * e, int * x, double *(func)(double))
	for(int i = 0; i<5; i++)
	{
		cout<<c[i]<<"  ";
	}
	cout<<endl;
	MyMap(b, b+5, d, square);  //MyMap(double * s,double * e, double * x, double *(func)(double))
	for(int i = 0; i<5; i++)
	{
		cout<<d[i]<<"  ";
	}
	cout<<endl;
	return 0;
}

