/*
�������������㷨��������c++������������� 
Week7
����������ļ����� 
дһ�����򣬽��ļ� in.txt ������������������� out.txt
��д����ʹ�ö����Ʒ�ʽ��Cars.dat�ļ�д��name��date��price������ȡ��ʾ���޸�
ʵ���ļ��������� 
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
	ofstream output("CarInfo.dat", ios::out|ios::binary);  //�����Ʒ�ʽд 
	if(!output)
	{
		cout<<"create CarInfo.dat error"<<endl;
		output.close();
		return -1;
	}
	cout<<"input Car info, like: golf 2018 15.49: "<<endl;
	while(cin>>c.name>>c.year>>c.price)
	{
		output.write((const char *)&c, sizeof(Car));  //���ļ�д���ڴ���&c��ʼ��sizeof(Car)�ֽڵ����ݣ�֮���ļ�дָ�������sizeof(Car)���ֽ� 
	}
	output.close();
	ifstream input("CarInfo.dat", ios::in|ios::binary);
	if(!input)
	{
		cout<<"open CarInfo.dat error"<<endl;
		input.close();
		return -1;
	}
	while(input.read((char *)&c, sizeof(Car)))  //���ļ��Ķ�ָ�������sizeof(Car)�����ݵ��ڴ��&c�� 
	{
		cout<<"Car name: "<<c.name<<";  Car year: "<<c.year<<";  Car price: "<<c.price*10000<<endl;
	}
	input.close();
	cout<<"Modify the second car name to \"HondaCivic\": "<<endl;
	ofstream output_1("CarInfo.dat", ios::in|ios::binary);
	output_1.seekp(1*sizeof(Car), ios::beg); //�ƶ��ļ�ָ����Ҫ�޸Ĵ�, ��ios::beg���ļ���ͷ�������1*sizeof(Car)���ֽ� 
	output_1.write("HondaCivic", strlen("HondaCivic")+1);  //һ���ַ�ռһ���ֽ� 
	output_1.close();
	ifstream input_1("CarInfo.dat", ios::ate|ios::binary); //ios::ateģʽʹ�ļ�ָ��ָ���ļ�β 
	if(!input_1)
	{
		cout<<"open CarInfo.dat error"<<endl;
		input_1.close();
		return -1;
	}
	int file_len = input_1.tellg();  //�ļ�ָ��ָ���ļ�β��ʹ��tellg()������ȡ�ļ�ָ��λ�ã����ļ��Ĵ�С(�ֽ���) 
	cout<<"file length: "<<file_len<<endl;
	input_1.seekg(0, ios::beg); //ʹ�ļ���ָ��ָ���ļ�ͷ 
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
			while(in.read(&c, 1))  //���ַ���ȡ���� 
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
 
