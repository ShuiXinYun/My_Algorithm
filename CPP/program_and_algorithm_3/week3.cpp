
/*
北大程序设计与算法（三）：c++面向对象程序设计
Week3
静态成员:
访问静态成员的4种方式, 类名::静态成员, 对象名.静态成员, 指向对象的指针->静态成员, 对象引用.静态成员
静态成员的使用：必须在文件中对静态成员变量进行一次说明或初始化, 静态成员函数不能访问非静态成员或使用非静态成员函数
友元：友元函数、友元类, 友元类之间的关系不能继承和传递 
常量成员函数
*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

class Cat; //Dog类中使用frient Cat, 先声明 

class Dog
{
private:
	string name;
	int age;
public:
	//		static int ndog = 0;
	static int ndog;
	static void ndog_plus();
	friend ostream & operator<<(ostream & o, const Dog & d);  //友元函数, 可访问类中的所有成员 
	friend Cat;
	
	Dog()
	{
		name = "default";
		age = 0;
	}
	
	Dog(string n, int a) :name(n), age(a)
	{
	}
	~Dog()
	{
	}

};

int Dog::ndog = 0;

void Dog::ndog_plus()
{
	//	cout << name << endl; // 静态成员函数不能访问非静态成员或使用非静态成员函数
	ndog++;
}

ostream & operator << (ostream & o, const Dog & d)
{
	o << "Dog name: " << d.name << ", his age: " << d.age <<endl; //对象引用访问静态成员 
	return o;
}

class Cat
{
	public:
		string name;
		int age;
		friend ostream & operator << (ostream & o, const Cat & c);
		friend Dog; //友元类, 可访问Dog类的所有成员 
		Dog dog_friend;
		Cat()
		{
			name = "default";
			age = 0;
		}
		Cat(string n, int a, Dog d):name(n), age(a), dog_friend(d)
		{}
		~Cat()
		{}
};

ostream & operator << (ostream & o, const Cat & c)
{
	cout << "Cat name: " << c.name << ", his age:" << c.age << "\nhis friend: \n" << c.dog_friend << endl;
	return o;
}

	int main()
{
	cout << "sizeof(Dog): " << sizeof(Dog) << endl;
	Dog corgi = Dog("short leg corgi", 2);
	Dog::ndog_plus();  //类名访问静态成员 
	cout << corgi;
	Dog pug = Dog("pug the boss", 5);
	pug.ndog_plus();
	Dog *ptr_pug = &pug;
	cout << pug;
	
	cout << "Dog nums: " << ptr_pug->ndog << ", same as " << pug.ndog << endl;//对象指针、对象访问静态成员
	Cat catty = Cat("cute catty", 2, corgi);
	cout << catty;
	return 0;
}



