/*
北大程序设计与算法（三）：c++面向对象程序设计 
Week7
输入输出和文件操作 
写一个程序，将文件 in.txt 里面的整数排序后，输出到 out.txt
编写程序，使用二进制方式向Cars.dat文件写入name、date、price，并读取显示，修改
实现文件拷贝程序 
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int io_func_1()
{
	ifstream input("in.txt", ios::in);
	if(!input)
	{
		cout<<"open in.txt error"<<endl;
		input.close();
		return -1; 
	}
	ofstream output("out.txt", ios::out);
	if(!output)
	{
		cout<<"create out.txt error"<<endl;
		output.close();
		return -1; 
	}
	vector<int> vec;
	int t;
	while(input>>t)
	{
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i<vec.size(); i++)
	{
		output<<vec[i]<<"  ";
	}
	input.close();
	output.close();
	return 0;
}

struct Car
{
	char name[100];
	int year;
	double price;
};

int io_func_2()
{
	Car c;
	ofstream output("CarInfo.dat", ios::out|ios::binary);  //二进制方式写 
	if(!output)
	{
		cout<<"create CarInfo.dat error"<<endl;
		output.close();
		return -1;
	}
	cout<<"input Car info, like: golf 2018 15.49: "<<endl;
	while(cin>>c.name>>c.year>>c.price)
	{
		output.write((const char *)&c, sizeof(Car));  //向文件写入内存中&c开始的sizeof(Car)字节的内容，之后将文件写指针向后移sizeof(Car)个字节 
	}
	output.close();
	ifstream input("CarInfo.dat", ios::in|ios::binary);
	if(!input)
	{
		cout<<"open CarInfo.dat error"<<endl;
		input.close();
		return -1;
	}
	while(input.read((char *)&c, sizeof(Car)))  //从文件的读指针出读入sizeof(Car)个内容到内存的&c处 
	{
		cout<<"Car name: "<<c.name<<";  Car year: "<<c.year<<";  Car price: "<<c.price*10000<<endl;
	}
	input.close();
	cout<<"Modify the second car name to \"HondaCivic\": "<<endl;
	ofstream output_1("CarInfo.dat", ios::in|ios::binary);
	output_1.seekp(1*sizeof(Car), ios::beg); //移动文件指针至要修改处, 从ios::beg即文件开头，向后移1*sizeof(Car)个字节 
	output_1.write("HondaCivic", strlen("HondaCivic")+1);  //一个字符占一个字节 
	output_1.close();
	ifstream input_1("CarInfo.dat", ios::ate|ios::binary); //ios::ate模式使文件指针指向文件尾 
	if(!input_1)
	{
		cout<<"open CarInfo.dat error"<<endl;
		input_1.close();
		return -1;
	}
	int file_len = input_1.tellg();  //文件指针指向文件尾，使用tellg()方法获取文件指针位置，即文件的大小(字节数) 
	cout<<"file length: "<<file_len<<endl;
	input_1.seekg(0, ios::beg); //使文件读指针指向文件头 
	cout<<"after modify: "<<endl;
	while(input_1.read((char *)&c, sizeof(Car)))
	{
		cout<<"Car name: "<<c.name<<";  Car year: "<<c.year<<";  Car price: "<<c.price*10000<<endl;
	}
	input_1.close();
	return 0;
}

int file_copy()
{
	ifstream in("CarInfo.dat", ios::in|ios::binary);
	ofstream out("Carinfo_bk.dat", ios::out|ios::binary);
	if(!in)
	{
		cout<<"file read error"<<endl;
		in.close(); 
		return -1;
	}
	else
	{
		if(!out)
		{
			cout<<"backup file create error"<<endl;
			out.close();
			return -1;
		}
		else
		{
			char c;
			while(in.read(&c, 1))  //逐字符读取拷贝 
			{
				out.write(&c, 1);
			}
			cout<<"backup succeess"<<endl;
		}
	}
	in.close();
	out.close();	
	return 0;
} 

int main()
{
//	io_func_1();
//	io_func_2();
	file_copy();
	return 0;
}
 
