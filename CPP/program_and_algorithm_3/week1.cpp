/* 
�������������㷨��������c++������������� 
Week1
����
const: const������ָ�롢���� 
��̬�ڴ����
inline�������� 
*/

#include<cstdio>
#include<iostream> 

const int MAX_SIZE = 100;

void swap(int & a, int & b)
{
	a^=b;
	b^=a;
	a^=b;
}

void print_char_array(const char * s)
{
	while(*s)
	{
		printf("%c", *s);
		s++;
	}
}

inline void test_const() //inline���������ɼ��ٺ������õ�ʱ�� 
{
	char s[MAX_SIZE] = "hello world!\n";
	int a = 0, b = 1;
	printf("a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("after swap, a: %d, b: %d\n", a, b);
	print_char_array(s); 
}

int main()
{
	test_const();
	char * s1 = new char[MAX_SIZE];
//	s1 = "hello world again!"; //�˾䵼�±���, ����delete, s1ָ��ı��� 
	delete [] s1;
	return 0;
}
