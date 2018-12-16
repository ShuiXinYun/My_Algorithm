/*
北大程序设计与算法（一）：c语言程序设计 
Week4
使用freopen重新定向文件 
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
