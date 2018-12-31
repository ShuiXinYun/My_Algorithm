/* 
北大程序设计与算法（三）：c++面向对象程序设计 
Week4
改善4.2程序, 编写同类对象的赋值重载函数
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
		String & operator = (const String & s); //使用引用的目的：a=b=c, (a=b)=c的情况 
};

String & String::operator = (char *s)
{
	delete [] str;
	str = new char[strlen(s)+1];
	strcpy(str, s);
	return *this;
}

String & String::operator = (const String & s)
{
	if(this == &s)
	{
		return *this;
	}
	delete [] this->str;
	this->str = new char[strlen(s.str)+1];
	strcpy(this->str, s.str);
	return *this; 
}

void test_String()
{
	String st1, st2;
	st1 = "hello world"; //st1.operator = ("hello world")
	st2 = st1; //st2.operator = (st1)
	cout<<st1.c_str()<<endl;
}

int main()
{
	test_String();
	return 0;
}





