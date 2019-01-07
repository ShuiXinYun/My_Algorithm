/*
北大程序设计与算法（三）：c++面向对象程序设计 
Week6
多态 
几何形体处理程序:
Input:
第一行是几何形体数目n（不超过100).下面有n行，每行以一个字母c开头.
若 c 是 ‘R’，则代表一个矩形，本行后面跟着两个整数，分别是矩形的宽和高；
若 c 是 ‘C’，则代表一个圆，本行后面跟着一个整数代表其半径
若 c 是 ‘T’，则代表一个三角形，本行后面跟着三个整数，代表三条边的长度
Output:
按面积从小到大依次输出每个几何形体的种类及面积。每行一个几何形体，输出格式为：
形体名称：面积 
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Shape
{
	public:
		double area = 0;
		virtual string get_type() = 0; 
		virtual double get_area() = 0;
		//一般包含虚函数的类，其析构函数也声明为虚函数 
		virtual ~Shape() 
		{
		}
};

 
class Rectangle:public Shape
{
	public:
		double length, width;
		string get_type()
		{
			return "Rectangle";
		}
		double get_area()
		{
			area = length*width;
			return area;
		}
		virtual ~Rectangle()
		{
		}
};

class Circle:public Shape
{
	public:
		double radius;
		string get_type()
		{
			return "Circle";
		}
		double get_area()
		{
			area = 3.14*radius*radius;
			return area;
		}
		virtual ~Circle()
		{
		}
};

class Triangle:public Shape
{	
	public:
		double l1,l2,l3;
		string get_type()
		{
			return "Triangle";
		}
		double get_area()
		{
			
			double p =(l1+l2+l3)/2;
			area = sqrt(p*(p-l1)*(p-l2)*(p-l3));
			return area;
		}
		virtual ~Triangle()
		{
		}
};

//用于sort()的比较函数 
bool cmp(Shape * s1, Shape * s2)
{
	return s1->area <= s2->area;
}

void test_virtual()
{
	vector<Shape *> shape_vec;
	Rectangle * p_rec; 
	Circle * p_cir;
	Triangle * p_tri;
	char c;
	while(cin>>c)
	{
		if(c == '\n')
		{
			continue;
		}
		switch(c)
		{
			case('R'):
				p_rec = new Rectangle();
				cin>>p_rec->length>>p_rec->width;
				shape_vec.push_back(p_rec);  //将指向派生对象的指针赋给基类指针 
				break;
			case('C'):
				p_cir = new Circle();
				cin>> p_cir->radius; 
				shape_vec.push_back(p_cir);
				break;
			case('T'):
				p_tri = new Triangle();
				cin>>p_tri->l1>>p_tri->l2>>p_tri->l3;
				shape_vec.push_back(p_tri);
				break;
			default:
				break;
		}
	}
	for(int i = 0; i<shape_vec.size(); i++)
	{
		shape_vec[i]->get_area(); // 多态, 使用基类指针调用派生类的虚函数, 若基类指针指向派生类对象，则调用此派生类对象的虚函数 
		cout<<shape_vec[i]->get_type()<<": "<<shape_vec[i]->area<<endl;
	}
	sort(shape_vec.begin(), shape_vec.end(), cmp);
	cout<<"after sort:"<<endl;
	for(int i = 0; i<shape_vec.size(); i++)
	{
		cout<<shape_vec[i]->get_type()<<": "<<shape_vec[i]->area<<endl;
	}
	for(int i = 0; i<shape_vec.size(); i++)
	{
		delete shape_vec[i];
	}
}

int main()
{
	test_virtual();
	return 0;
}
