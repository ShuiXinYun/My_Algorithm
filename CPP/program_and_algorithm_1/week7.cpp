/*
�������������㷨��һ����c���Գ������ 
Week7
�ַ�����
��������, scanf, cin���뵽�ո�
������cin.getline(), gets()
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
	cin.getline(a, sizeof(a)/sizeof(char)); //�Զ����\0, δ����ı������������� 
	cout<<a<<" strlen(a): "<<strlen(a)<<endl;  //strlen(a)������\0 
	gets(a);  //���ܵ���Խ�� 
	cout<<a<<endl;
}

int main()
{
	strfuc();
	return 0;
}
