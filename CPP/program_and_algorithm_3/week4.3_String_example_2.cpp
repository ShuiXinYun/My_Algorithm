/* 
�������������㷨��������c++������������� 
Week4
����4.2����, ��дͬ�����ĸ�ֵ���غ���
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
			str[0]=0;//���ַ� 
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
		String & operator = (const String & s); //ʹ�����õ�Ŀ�ģ�a=b=c, (a=b)=c����� 
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





