/*
�������������㷨��һ����c���Գ������ 
Week9
ָ�����ַ���
voidָ��
�ַ��������⺯�� 
�ڴ�����⺯��
����ָ�� 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

//ָ�����ַ��� 
void ptr_and_str()
{
	char *p = "hello world";
	printf("p: %s, p[1]: %c\n", p, p[1]);
} 

//voidָ�� 
void void_ptr()
{
	void *p;
	int a =1000;
	p = &a; //�����κ�����ָ���voidָ�븳ֵ
	printf("p is a void pointer point to int 1000, *(int *)p: %d", *(int *)p); //ʹ��* void_ptr ��Ҫ��ָ������ת�� 
}

//�ڴ��������, ��cstring������
//memset�������÷���ֻ��������ʼ��char���͵�����ģ�Ҳ����˵����ֻ����0x00-0xFF�ĸ�ֵ
//memcpy��src��ʼ��n���ֽڿ�����dest 
void memfunc() 
{
	int a[10];
	printf("\na:\n");
	for(int i = 0;i<10;i++)
		printf("%d ",a[i]);
	memset(a, 1, sizeof(a));  //void * memset(void * dest, int ch, int n); ��dest��ʼ��n���ֽھ���Ϊch 
	printf("\na after memset 1:\n");  // 16843009, memset���ֽڸ�ֵ��ÿ������Ԫ�ص�ֵʵ������0x01010101��ʮ���Ƶ�16843009
	for(int i = 0;i<10;i++)
		printf("%d ",a[i]);
	memset(a, 0, sizeof(a));
	printf("\na after memset 0:\n");  // 0, ��0�ǿ��Ե� 
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
�ַ��������⺯��
strcat: char * strcat(char * dest, char * src);
strchr: const char * strchr(const char * str, int character);
strrchr: const char * strrchr(const char * str, int character);
strstr: const char * strstr(const char * str1, const char str2);
strcmp: const int strcmp(const char * str1, const char * str2);
stricmp: const int strcmp(const char * str1, const char * str2); //���ƴ�Сд 
strcpy: char * strcpy(char * dest, const char * src, size_t num);
strlen: size_t strlen(const char * str); 
strlwr: char * strlwr(char * str);
strupr: char * strupr(char * str);
strncat: char * strncat(char * dest, char * src, int num);
strncmp: int strncmp(const char * str1, const char * str2, int n);
strncpy: char * strcpy(char * dest, const char * src, size_t num);
strtok: char * strtok(char * str, const char * delim) ; //�������øú������ɴΣ����Դ�str�������ȡ�����ַ���delim�е��ַ��ָ��������ɸ��Ӵ��� 
atoi: int atoi(char * str);
atof: double atof(char * str);
itoa: char * itoa(int value, char * str, int radix); ������value��radix������ʽд��str 
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
