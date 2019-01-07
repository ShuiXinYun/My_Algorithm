/*
�������������㷨��������c++������������� 
Week6
��̬ 
�������崦�����:
Input:
��һ���Ǽ���������Ŀn��������100).������n�У�ÿ����һ����ĸc��ͷ.
�� c �� ��R���������һ�����Σ����к�����������������ֱ��Ǿ��εĿ�͸ߣ�
�� c �� ��C���������һ��Բ�����к������һ������������뾶
�� c �� ��T���������һ�������Σ����к�������������������������ߵĳ���
Output:
�������С�����������ÿ��������������༰�����ÿ��һ���������壬�����ʽΪ��
�������ƣ���� 
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
		//һ������麯�����࣬����������Ҳ����Ϊ�麯�� 
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

//����sort()�ıȽϺ��� 
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
				shape_vec.push_back(p_rec);  //��ָ�����������ָ�븳������ָ�� 
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
		shape_vec[i]->get_area(); // ��̬, ʹ�û���ָ�������������麯��, ������ָ��ָ���������������ô������������麯�� 
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
