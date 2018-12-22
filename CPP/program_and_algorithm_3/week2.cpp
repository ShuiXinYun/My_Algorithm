/* 
�������������㷨��������c++������������� 
Week2
���캯����
���ƹ��캯�����������õ������������һ�������ʼ����һ�����󡢺�����������������ֵΪ���� 
����ת�����캯�� 
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
	//��ĳ�Ա�����ɷ���ͬ������˽�г�Ա���ɷ���car��˽�г�Ա
	this->name = car.name;
	this->price = car.price;
	cout<<"copy constructor"<<endl;
}

void print_Car_info(const MyCar & car)
{
	cout<<"car name: "<<car.name<<", car price: "<<car.price<<endl;
}

MyCar copy_car(MyCar car) //��������ʱ��ʹ�ÿ������캯��, ��ʹ������, ��ʹ�ÿ������캯�� 
{
	MyCar tmp_car = car; // ��ʼ������,ʹ�ÿ������캯�� 
	return car; //��������ʱ��ʹ�ÿ������캯�� 
} 

void test_constructor()
{
	MyCar car1; //Ĭ�Ϲ��캯�� 
	MyCar car2("Golf",150000.0); //�������캯�� 
	MyCar car3(car2); //car2��ʼ��car1, �������캯�� 
	car1 = car2; //����ֵ����ʹ�ÿ������캯�� 
	MyCar car4 = copy_car(car2); //ʹ�������ο������캯�� 
	print_Car_info(car1);
}

int main()
{
	test_constructor();
	return 0;
}
