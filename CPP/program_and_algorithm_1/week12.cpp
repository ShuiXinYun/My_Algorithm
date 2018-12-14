/*
�������������㷨��һ����c���Գ������ 
Week12
c��qsort()
STL��sort()
STL��binary_search, lower_bound, upper_bound 
bool binary_search(ArrayName, ArrayName + N, value); bool binary_search(ArrayName, ArrayName + N, value, SortStructName());
T * lower_bound(ArrayName, ArrayName + N, value); T * lower_bound(ArrayName, ArrayName + N, value, SortStructName)
lower_bound(), ���Ҵ��ڵ���value, �±���С��Ԫ��, �Ҳ����򷵻�N��ָ��; upper_bound(),  ���Ҵ���value, �±���С��Ԫ��, �Ҳ����򷵻�N��ָ��
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>

using namespace std;
#define NSIZE 10

//sort()�Ĵ�С����ȽϽṹ 
struct mysort
{
	bool operator()(const int &a1, const int &a2)
	{
		if(a1<a2)  //�ı�˴������Ƿ�Ϊ�ȶ����� 
			return true;
		else
			return false;
	}
};

//sort()����λ����С����ȽϽṹ 
struct mysort_by_unitsdigit
{
	bool operator()(const int &a1, const int &a2)
	{
		if(a1%10 < a2%10)  //�ı�˴������Ƿ�Ϊ�ȶ�����, ���ӵȺ�Ϊ�ȶ�����, <=Ϊ���ȶ����� 
			return true;
		else
			return false;
	}
};

//qsort()�ıȽϺ��� 
int mycomp(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return -1;
	else if (*(int *)a < *(int *)b)
		return 1;
	else
		return 0;
}

void print_arr(int *a, int size)
{
	for(int i = 0; i<size; i++)
		printf("%d ", a[i]); 
	printf("\n");
}

void test_sort()
{
	cout<<"------sort test------"<<endl;
	int a[NSIZE] = {100, 19, 38, 47, 56, 35 , 14, 23, 82, 91};
	printf("a: ");
	print_arr(a, 10);
	sort(a,a+NSIZE);
	printf("a after sort: ");
	print_arr(a, 10);  
	sort(a,a+NSIZE,greater<int>());
	printf("a after greater sort: ");
	print_arr(a, 10);
	sort(a,a+NSIZE,mysort());
	printf("a after smaller sort: ");
	print_arr(a, 10);
	sort(a, a+NSIZE, mysort_by_unitsdigit());
	printf("a after sort by units digit: ");
	print_arr(a, 10);
	qsort(a,NSIZE,sizeof(int),mycomp);
	printf("a after qsort: ");
	print_arr(a, 10);
}

//STL binary_search����true/false 
void test_binary_search()
{
	cout<<"------binary search test------"<<endl;
	int a[NSIZE] = {109, 19, 38, 47, 56, 35 , 14, 23, 82, 91};
	printf("a: ");
	print_arr(a, NSIZE);
	sort(a, a+NSIZE);
	printf("a after sort: ");
	print_arr(a, NSIZE);
	printf("binary search 47 in a: %d\n", binary_search(a, a+NSIZE, 47));
	sort(a, a+NSIZE, mysort_by_unitsdigit());
	printf("a sort by units digit:");
	print_arr(a, NSIZE);
	printf("binary search 80 in a by unitsdigit: %d", binary_search(a, a+NSIZE, 80, mysort_by_unitsdigit())); //�Ƚϵ��Ǹ�λ�� 
}

//lowerbound��upperbound����T * 
void test_bound() 
{
	cout<<"------lowerbound & upperbound test------"<<endl;
	int a[NSIZE] = {109, 19, 38, 47, 56, 35 , 14, 23, 82, 91};
	printf("a: ");
	print_arr(a, NSIZE);
	sort(a, a+NSIZE);
	printf("a after sort: ");
	print_arr(a, NSIZE);
	printf("lowerbound n-th 38 in sorted a: %d, value: %d", lower_bound(a, a+NSIZE, 38)-a, *lower_bound(a, a+NSIZE, 38)); //�ҵ�38��λ�� 
	printf("\nupperbound n-th 38 in sorted a: %d, value: %d", upper_bound(a, a+NSIZE, 38)-a, *upper_bound(a, a+NSIZE, 38)); // ����38��λ�� 
}

int main()
{
	test_sort();
	test_binary_search();
	test_bound();
	return 0;
}
