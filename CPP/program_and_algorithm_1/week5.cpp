/*
�������������㷨��һ����c���Գ������ 
Week5
ɸ����n���ڵ�����
��ά����Ԫ���ڴ��ַ������ 
*/
#include<iostream>

using namespace std;

//ɸ����n���ڵ�����

//��ά����Ԫ���ڴ��ַ������  
void _2dmatrix()
{
	int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
	cout<<"matrix a:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j = 0; j<4; j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"a[0] address: "<<a[0]<<" a[1] address:"<<a[1]<<" a[2] address: "<<a[2]<<endl;
	cout<<"a[1] - a[0]: "<<a[1] - a[0]<<endl;
	cout<<"a[0][1] address: "<<&a[0][1]<<" a[0][2] address:"<<&a[0][2]<<" a[0][3] address: "<<&a[0][3]<<endl;
}

int main()
{
	_2dmatrix();
	return 0;
}
