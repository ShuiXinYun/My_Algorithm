/*
北大程序设计与算法（一）：c语言程序设计 
Week12
c的qsort()
STL的sort()
STL的binary_search, lower_bound, upper_bound 
bool binary_search(ArrayName, ArrayName + N, value); bool binary_search(ArrayName, ArrayName + N, value, SortStructName());
T * lower_bound(ArrayName, ArrayName + N, value); T * lower_bound(ArrayName, ArrayName + N, value, SortStructName)
lower_bound(), 查找大于等于value, 下标最小的元素, 找不到则返回N处指针; upper_bound(),  查找大于value, 下标最小的元素, 找不到则返回N处指针
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>

using namespace std;
#define NSIZE 10

//sort()的从小到大比较结构 
struct mysort
{
	bool operator()(const int &a1, const int &a2)
	{
		if(a1<a2)  //改变此处更改是否为稳定排序 
			return true;
		else
			return false;
	}
};

//sort()按个位数从小到大比较结构 
struct mysort_by_unitsdigit
{
	bool operator()(const int &a1, const int &a2)
	{
		if(a1%10 < a2%10)  //改变此处更改是否为稳定排序, 不加等号为稳定排序, <=为不稳定排序 
			return true;
		else
			return false;
	}
};

//qsort()的比较函数 
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

//STL binary_search返回true/false 
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
	printf("binary search 80 in a by unitsdigit: %d", binary_search(a, a+NSIZE, 80, mysort_by_unitsdigit())); //比较的是个位数 
}

//lowerbound、upperbound返回T * 
void test_bound() 
{
	cout<<"------lowerbound & upperbound test------"<<endl;
	int a[NSIZE] = {109, 19, 38, 47, 56, 35 , 14, 23, 82, 91};
	printf("a: ");
	print_arr(a, NSIZE);
	sort(a, a+NSIZE);
	printf("a after sort: ");
	print_arr(a, NSIZE);
	printf("lowerbound n-th 38 in sorted a: %d, value: %d", lower_bound(a, a+NSIZE, 38)-a, *lower_bound(a, a+NSIZE, 38)); //找到38的位置 
	printf("\nupperbound n-th 38 in sorted a: %d, value: %d", upper_bound(a, a+NSIZE, 38)-a, *upper_bound(a, a+NSIZE, 38)); // 不含38的位置 
}

int main()
{
	test_sort();
	test_binary_search();
	test_bound();
	return 0;
}
