/* 
北大程序设计与算法（三）：c++面向对象程序设计 
Week4
运算符重载
编写String类, bug版 
重载 = 实现字符串对String对象的赋值
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

class String
{
	private:
		char * str;
	public:
		String():str(new char[1])
		{
			str[0]=0;//空字符 
		}
		~String()
		{
			delete [] str;
		}
		char * c_str()
		{
			return str;
		}
		String & operator = (char * s);
};

String & String::operator = (char *s)
{
	delete [] str;
	str = new char[strlen(s)+1];
	strcpy(str, s);
	return *this;
}

void test_String()
{
	String st1, st2;
	st1 = "hello world"; //st1.operator = ("hello world")
	st2 = st1; //此处导致bug, 因为st1和st2均指向同一处, st1和st2生命周期结束后对同一数组delete了两次, 且st2指向的内存空间不会被delete 
	cout<<st1.c_str()<<endl;
}

int main()
{
	test_String();
	return 0;
}





