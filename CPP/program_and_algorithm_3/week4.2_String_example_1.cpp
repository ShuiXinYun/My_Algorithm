/* 
�������������㷨��������c++������������� 
Week4
���������
��дString��, bug�� 
���� = ʵ���ַ�����String����ĸ�ֵ
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
	st2 = st1; //�˴�����bug, ��Ϊst1��st2��ָ��ͬһ��, st1��st2�������ڽ������ͬһ����delete������, ��st2ָ����ڴ�ռ䲻�ᱻdelete 
	cout<<st1.c_str()<<endl;
}

int main()
{
	test_String();
	return 0;
}





