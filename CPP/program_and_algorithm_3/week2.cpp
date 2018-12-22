/* 
北大程序设计与算法（三）：c++面向对象程序设计 
Week2
构造函数：
复制构造函数及其起作用的三种情况：用一个对象初始化另一个对象、函数参数、函数返回值为对象 
类型转换构造函数 
*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
 
class MyCar
{
	private:
		string name;
		double price;
	public:
		MyCar()
		{
			name = " ";
			price = 0.0;
			cout<<"default constructor"<<endl;
		}
		MyCar(const MyCar & car);
		MyCar(string s, double p):name(s),price(p)
		{
			cout<<"name and price constructor"<<endl;
		}
		~MyCar()
		{ 
			cout<<"deconstructor"<<endl;
		}
		friend void print_Car_info(const MyCar & car);
};
 
MyCar::MyCar(const MyCar & car)
{
	//类的成员函数可访问同类对象的私有成员，可访问car的私有成员
	this->name = car.name;
	this->price = car.price;
	cout<<"copy constructor"<<endl;
}

void print_Car_info(const MyCar & car)
{
	cout<<"car name: "<<car.name<<", car price: "<<car.price<<endl;
}

MyCar copy_car(MyCar car) //函数调用时，使用拷贝构造函数, 若使用引用, 则不使用拷贝构造函数 
{
	MyCar tmp_car = car; // 初始化对象,使用拷贝构造函数 
	return car; //函数返回时，使用拷贝构造函数 
} 

void test_constructor()
{
	MyCar car1; //默认构造函数 
	MyCar car2("Golf",150000.0); //参数构造函数 
	MyCar car3(car2); //car2初始化car1, 拷贝构造函数 
	car1 = car2; //对象赋值并不使用拷贝构造函数 
	MyCar car4 = copy_car(car2); //使用了三次拷贝构造函数 
	print_Car_info(car1);
}

int main()
{
	test_constructor();
	return 0;
}
