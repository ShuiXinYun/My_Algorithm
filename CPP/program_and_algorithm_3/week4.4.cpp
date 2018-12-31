/*
北大程序设计与算法（三）：c++面向对象程序设计
Week4
编写可变长整型数组类，使之能如下使用：
int main()
{
CArray a; //开始里的数组是空的
for( int i = 0;i < 5;++i)
a.push_back(i);
CArray a2,a3;
a2 = a;
for( int i = 0; i < a.length(); ++i )
cout << a2[i] << " " ;
a2 = a3; //a2是空的
for( int i = 0; i < a2.length(); ++i ) //a2.length()返回0
cout << a2[i] << " ";
cout << endl;
a[3] = 100;
CArray a4(a);
for( int i = 0; i < a4.length(); ++i )
cout << a4[i] << " ";
return 0;
}
*/
# include<iostream>
# include<cstdio>
using namespace std;

class CArray
{
private:
	int * _array = new int[1];
	int size;
public:
	CArray()
	{
		*(_array + 0) = 0;
		size = 0;
	}
	//拷贝构造函数
	CArray(const CArray & a)
	{
		if (a.size == 0)
		{
			delete[] _array;
			_array = new int[1];
			*(_array + 0) = 0;
			size = 0;
		}
		else
		{
			delete[] _array;
			size = a.size;
			_array = new int[a.size];
			for (int i = 0; i<a.size; i++)
			{
				*(_array + i) = *(a._array + i);
			}
		}	
	}
	~CArray()
	{
		delete[] _array;
	}
	void push_back(int num);
	int & operator [] (int i); //重载[]运算符, 注意返回值类型为引用, 因为需执行如a[i] = 100;的操作
	int length();
	CArray & operator = (const CArray & a); //重载赋值运算符
	friend ostream & operator << (ostream & o, const CArray & a); //重载流插入运算符
};

void CArray::push_back(int num)
{
	int * _arraytemp = new int[size + 1];
	for (int i = 0; i<size; i++)
	{
		*(_arraytemp + i) = *(_array + i);
	}
	*(_arraytemp + size) = num;
	++size;
	delete [] _array;
	_array = _arraytemp;
}

int CArray::length()
{
	return this->size;
}

int & CArray::operator [] (int i)
{
	return *(_array + i);
}

CArray & CArray::operator = (const CArray & a)
{
	if (a.size == 0)
	{
		delete[] _array;
		_array = new int[1];
		*(_array + 0) = 0;
		size = 0;
	}
	else
	{
		delete[] _array;
		size = a.size;
		_array = new int[a.size];
		for (int i = 0; i<a.size; i++)
		{
			*(_array + i) = *(a._array + i);
		}
	}
	return *this;
}

ostream & operator << (ostream & output, const CArray & a)
{
	output << "the CArray object length: " << a.size << endl;
	output << "the elements:" << endl;
	for (int i = 0; i < a.size; i++)
	{
		output << *(a._array + i) << "  ";
	}
	output << endl;
	return output;
}

void test_CArray()
{
	CArray a, a2, a3; //开始里的数组是空的
	for (int i = 0; i < 5; ++i)
		a.push_back(i); 
	cout << "a:\n" << a;
	a2 = a;
	cout << "a2:\n " << a2;
	a2 = a3; //a2是空的
	cout << "a2: \n" << a2;
	a[3] = 100;
	cout << "a[3]=100, a:" << endl;
	cout << a;
	CArray a4(a);
	cout << "create a4 use a, a4: \n" <<a4<< endl;
}
/*
a:
the CArray object length: 5
the elements:
0  1  2  3  4
a2:
 the CArray object length: 5
the elements:
0  1  2  3  4
a2:
the CArray object length: 0
the elements:

a[3]=100, a:
the CArray object length: 5
the elements:
0  1  2  100  4
create a4 use a, a4:
the CArray object length: 5
the elements:
0  1  2  100  4
*/


int main()
{
	test_CArray();
	system("pause");
	return 0;
}

