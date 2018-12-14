/*
北大程序设计与算法（一）：c语言程序设计 
Week9
指针与字符串
void指针
字符串操作库函数 
内存操作库函数
函数指针 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

//指针与字符串 
void ptr_and_str()
{
	char *p = "hello world";
	printf("p: %s, p[1]: %c\n", p, p[1]);
} 

//void指针 
void void_ptr()
{
	void *p;
	int a =1000;
	p = &a; //可用任何类型指针给void指针赋值
	printf("p is a void pointer point to int 1000, *(int *)p: %d", *(int *)p); //使用* void_ptr 需要做指针类型转换 
}

//内存操作函数, 在cstring中声明
//memset的正规用法是只能用来初始化char类型的数组的，也就是说，它只接受0x00-0xFF的赋值
//memcpy将src开始的n个字节拷贝到dest 
void memfunc() 
{
	int a[10];
	printf("\na:\n");
	for(int i = 0;i<10;i++)
		printf("%d ",a[i]);
	memset(a, 1, sizeof(a));  //void * memset(void * dest, int ch, int n); 将dest开始的n个字节均置为ch 
	printf("\na after memset 1:\n");  // 16843009, memset按字节赋值，每个数组元素的值实际上是0x01010101即十进制的16843009
	for(int i = 0;i<10;i++)
		printf("%d ",a[i]);
	memset(a, 0, sizeof(a));
	printf("\na after memset 0:\n");  // 0, 赋0是可以的 
	for(int i = 0;i<10;i++)
		printf("%d ",a[i]);
	int b[10];
	printf("\nb: \n");
	for(int i = 0;i<10;i++)
		printf("%d ",b[i]);
	memcpy(b ,a ,sizeof(a)); // void * memcpy(void * dest, void * src, int n);
	printf("\nb after memcpy: \n");
	for(int i = 0;i<10;i++)
		printf("%d ",b[i]);
}
/*
字符串操作库函数
strcat: char * strcat(char * dest, char * src);
strchr: const char * strchr(const char * str, int character);
strrchr: const char * strrchr(const char * str, int character);
strstr: const char * strstr(const char * str1, const char str2);
strcmp: const int strcmp(const char * str1, const char * str2);
stricmp: const int strcmp(const char * str1, const char * str2); //不计大小写 
strcpy: char * strcpy(char * dest, const char * src, size_t num);
strlen: size_t strlen(const char * str); 
strlwr: char * strlwr(char * str);
strupr: char * strupr(char * str);
strncat: char * strncat(char * dest, char * src, int num);
strncmp: int strncmp(const char * str1, const char * str2, int n);
strncpy: char * strcpy(char * dest, const char * src, size_t num);
strtok: char * strtok(char * str, const char * delim) ; //连续调用该函数若干次，可以从str中逐个抽取出被字符串delim中的字符分隔开的若干个子串。 
atoi: int atoi(char * str);
atof: double atof(char * str);
itoa: char * itoa(int value, char * str, int radix); 将整型value以radix进制形式写入str 
*/
void stringfunc()
{
	
}

int main()
{
	ptr_and_str();
	void_ptr();
	memfunc();
	void (* ptrf)();
	ptrf = stringfunc;
	ptrf(); 
//	system("pause"); //<cstdlib>
	return 0;
}
