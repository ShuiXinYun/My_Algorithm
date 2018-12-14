/*
北大程序设计与算法（一）：c语言程序设计 
Week7
字符串：
读入数组, scanf, cin读入到空格
读入行cin.getline(), gets()
<cstring>,
*/
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

void strfuc()
{
	char a[20];
//	scanf("%s", a); //hello world
//	printf("%s\n", a); 
//	cin>>a; //hello world
//	cout<<a<<endl;
	cin.getline(a, sizeof(a)/sizeof(char)); //自动添加\0, 未存入的保留在输入流中 
	cout<<a<<" strlen(a): "<<strlen(a)<<endl;  //strlen(a)不包含\0 
	gets(a);  //可能导致越界 
	cout<<a<<endl;
}

int main()
{
	strfuc();
	return 0;
}
