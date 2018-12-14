/*
北大程序设计与算法（一）：c语言程序设计 
Week11 
二分查找, lowerbound(), upperbound() 
*/
#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
#define NSIZE 10

using namespace std;

//冒泡排序
void bubble_sort(int *a, int size)
{
	for(int i = size-1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp =a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				//异或实现值互换 
//				a[j]^=a[j+1];
//				a[j+1]^=a[j];
//				a[j]^=a[j+1];
			}
		}
	}
} 

//二分查找
int mybinarysearch(int *a, int size, int key)
{
	int left =0, right = size-1;
	int mid;
	while(left<=right)
	{
		mid = left + (right -left)/2;
		if(a[mid]>key)
			right = mid - 1;
		else if(a[mid]<key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

//lowerbound 比给定整数小, 下标最大的元素 
int lowerbound(int *a, int size, int key)
{
	int lastpos = -1, left = 0, right = size - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(key <= a[mid])
		{
			right = mid - 1;
		}
		else
		{
			lastpos = mid;
			left = mid + 1;
		}	
	}
	return lastpos;
}

//upperbound 比给定整数小, 下标最大的元素 
int upperbound(int *a, int size, int key)
{
	int lastpos = -1, left = 0, right = size - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(key < a[mid])
		{
			lastpos = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}	
	}
	return lastpos;
}

void print_arr(int *a, int size)
{
	for(int i = 0; i<size; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[NSIZE] = {100, 79, 88, 7, 56, 5, 4, 23, 2, 1};
	cout<<"a:"<<endl;
	print_arr(a, NSIZE); 
	bubble_sort(a, sizeof(a)/sizeof(int));
	cout<<"a after sort:"<<endl;
	print_arr(a, NSIZE);
	cout<<"binary search 9 in a, index: "<<mybinarysearch(a, NSIZE, 9)<<endl;
	cout<<"lowerbound search 8 in a, index: "<<lowerbound(a, NSIZE, 88)<<endl;
	cout<<"upperbound search 8 in a, index: "<<upperbound(a, NSIZE, 88)<<endl;
}
