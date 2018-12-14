/*
北大程序设计与算法（一）：c语言程序设计 
Week10
结构与指针
static
static应用: strtok()的实现
 
简单排序: 选择排序, 插入排序，冒泡排序 
*/

#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
#define NSIZE 10

using namespace std;

// 结构与指针 
struct birthday
{
	int year;
	int month;
	int day;
};

struct student
{
	string name;
	double weight;
	birthday birth;
};

void test_struct()
{
	cout<<"------struct test------"<<endl;
	student st = {"june", 50.0, {1992, 1, 20}};
	student * ptrst = &st;
	cout<<"student name: "<<st.name<<", weight: "<<st.weight<<", birthday: "<<st.birth.year<<"-"<<st.birth.month<<"-"<<st.birth.day<<endl;
	cout<<"student name: "<<ptrst->name<<", weight: "<<ptrst->weight<<", birthday: "<<ptrst->birth.year<<"-"<<ptrst->birth.month<<"-"<<ptrst->birth.day<<endl;
 } 

//static

void static_func()
{
	static int tmp = 0;
	tmp ++;
	cout<<tmp;
}

void test_static() 
{
	cout<<"------static test------"<<endl;
	cout<<"static test 1:";
	static_func();
	cout<<"\nstatic test 2:";
	static_func();
	cout<<"\nstatic test 3:";
	static_func();
	cout<<endl;
}
//简单排序 
//选择排序, 时间复杂度O(n^2)
void selection_sort(int *a, int size)
{
	for(int i = 0; i<size-1; i++)
	{
		int tempindex = i;
		for(int j=i+1; j<size; j++)
		{
			if(a[j]<a[tempindex])
			{
				tempindex = j; //改变此处用来更改从小到大、从大到小排序 
			}
		}
		int tmp = a[i];
		a[i] = a[tempindex];
		a[tempindex] = tmp;
	}
}

//冒泡排序, 逆序 
void inversed_bubble_sort(int *a, int size)
{
	for(int i = size-1; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if(a[j]<a[j+1])
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

//插入排序
void insertion_sort(int arr[], int len)
{
    int i,j,temp;
    for (i=1;i<len;i++){
            temp = arr[i];
            for (j=i;j>0 && arr[j-1]>temp;j--)
                    arr[j] = arr[j-1];
            arr[j] = temp;
    }
}

void print_arr(int *a, int size)
{
	for(int i = 0; i<size; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void test_sort()
{
	cout<<"------sort test------"<<endl;
	int a[6] = {10, 29, 67, 55, 66, 89};
	cout<<"a: "<<endl;
	print_arr(a, 6);
	selection_sort(a, 6);
	cout<<"a after selection sort: "<<endl;
	print_arr(a, 6);
	inversed_bubble_sort(a, 6);
	cout<<"a after invesed bubble sort: "<<endl;
	print_arr(a, 6);
	insertion_sort(a, 6);
	cout<<"a after insertion sort: "<<endl;
	print_arr(a, 6);
}

int main()
{
	test_static();
	test_struct();
	test_sort();
	return 0;
}

