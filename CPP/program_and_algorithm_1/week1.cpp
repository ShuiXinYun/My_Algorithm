/* 
北大程序设计与算法（一）：c语言程序设计 
Week1
有符号数、无符号数
*/
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	short a = 0b0000000000000001;
	short b = 0b1111111111111111; //有符号负数：符号位为1, 其余位按绝对值取反后加1 
	unsigned int c = (unsigned int) b;
	cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
}
