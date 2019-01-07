/*
北大程序设计与算法（三）：c++面向对象程序设计 
Week8
函数模板和类模板 
使用函数模板实现Map函数
使用类模板实现pair 
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

