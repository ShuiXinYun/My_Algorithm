/*
�������������㷨��һ����c���Գ������ 
Week8
ָ��������, ָ������
*/

#include<iostream>

using namespace std;

//ָ��������, ָ������
void ptrfunc()
{
	int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
	int *p=a[0]; //int *p = &a[0][0], ��ά���鲻��ֱ������������ֵ,ָ�벻����[][]����(��֪������) 
	cout<<"matrix a:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j = 0; j<4; j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"p point to a, p address: "<<p<<"  p+1 address: "<<p+1<<endl;
	cout<<"p+4 point to a[1][0], *(p+4): "<<*(p+4)<<endl;
	
	int b[6] = {0,1,2,3,4,5};
	int *pp = b;
	cout<<"pp point to b:{0,1,2,3,4,5}"<<endl;
	cout<<"pointer [] func: pp[1] same as b[1], pp[1]: "<<pp[1]<<endl;
	pp++;
	cout<<"*pp after pp++: "<<*pp<<endl;
} 
 
int main()
{
	ptrfunc();
	return 0;
} 
