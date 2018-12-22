/* 
北大程序设计与算法（三）：c++面向对象程序设计 
Week1
引用
const: const常量、指针、引用 
动态内存分配
inline内联函数 
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

inline void test_const() //inline内联函数可减少函数调用的时间 
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
//	s1 = "hello world again!"; //此句导致报错, 不能delete, s1指向改变了 
	delete [] s1;
	return 0;
}
