/* 
�������������㷨��һ����c���Գ������ 
Week2
����������߼���������� 
%d, %c, %f, %lf, %lld, %x, %nd, %0nd, %.nf, %u
void ָ�� 
*/
#include<iostream>
#include<cstdio>

using namespace std;

//���������scanf��cin 
int scanf_cin()
{
	int a;
	float b;
	char c;
	double d;
	long e;
	long long f;
	printf("sizeof int: %d, float: %d, char: %d, double: %d, long: %d, long long: %d\n", sizeof(int), sizeof(float), sizeof(char), sizeof(double), sizeof(long), sizeof(long long));
	printf("input int,float,char,double,long,long long:\n");
	scanf("%d,%f,%c,%lf,%ld,%lld",&a,&b,&c,&d,&e,&f);
	printf("a:%d b:%f c:%c d:%lf e:%ld, f:%lld",a,b,c,d,e,f);
//	cin>>a>>b>>c>>d>>e>>f;
//	cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<" e: "<<e<<" f: "<<f<<endl;
	return 0; 
}

//�߼����Ʒ� 
int logic()
{
	int a =0,b=1;
	bool n = (a++)&&(b++);
	cout<<"a:"<<a<<" b:"<<b<<" n:"<<n<<endl; //1,1,0
	n = (a++)||(b++); 
	cout<<"a:"<<a<<" b:"<<b<<" n:"<<n<<endl; //2,1,1
	n = (a++)&&(b++); 
	cout<<"a:"<<a<<" b:"<<b<<" n:"<<n<<endl; //3,2,1
	return 0;
}

int main()
{
	int m =5;
	//voidָ�� 
	void *p;
	p = &m;
	int (*pfunc)();
	pfunc = scanf_cin;
	cout<<*(int *)p<<endl;
	pfunc();
	return 0;
}
