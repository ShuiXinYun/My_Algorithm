/*
�������������㷨��һ����c���Գ������ 
Week4
ʹ��freopen���¶����ļ� 
*/
#include<iostream>
using namespace std;

int main()
{
//	freopen("D:\\Devcpp\\test_in.txt","r",stdin);
	freopen("./test_in.txt","r",stdin);
	freopen("./test_out.txt","w",stdout);
	int n, mx = 0;
	printf("the inputs:\n");
	while(cin>>n)
	{
		printf("%d ", n);
		if(n>mx)
		{
			mx = n;
		}
	}
	printf("\nthe max: %d", mx);
	fclose(stdin);
	return 0;
}
