
/*
�������������㷨��������c++�������������
Week3
��̬��Ա:
���ʾ�̬��Ա��4�ַ�ʽ, ����::��̬��Ա, ������.��̬��Ա, ָ������ָ��->��̬��Ա, ��������.��̬��Ա
��̬��Ա��ʹ�ã��������ļ��жԾ�̬��Ա��������һ��˵�����ʼ��, ��̬��Ա�������ܷ��ʷǾ�̬��Ա��ʹ�÷Ǿ�̬��Ա����
��Ԫ����Ԫ��������Ԫ��, ��Ԫ��֮��Ĺ�ϵ���ܼ̳кʹ��� 
������Ա����
*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

class Cat; //Dog����ʹ��frient Cat, ������ 

class Dog
{
private:
	string name;
	int age;
public:
	//		static int ndog = 0;
	static int ndog;
	static void ndog_plus();
	friend ostream & operator<<(ostream & o, const Dog & d);  //��Ԫ����, �ɷ������е����г�Ա 
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
	//	cout << name << endl; // ��̬��Ա�������ܷ��ʷǾ�̬��Ա��ʹ�÷Ǿ�̬��Ա����
	ndog++;
}

ostream & operator << (ostream & o, const Dog & d)
{
	o << "Dog name: " << d.name << ", his age: " << d.age <<endl; //�������÷��ʾ�̬��Ա 
	return o;
}

class Cat
{
	public:
		string name;
		int age;
		friend ostream & operator << (ostream & o, const Cat & c);
		friend Dog; //��Ԫ��, �ɷ���Dog������г�Ա 
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
	Dog::ndog_plus();  //�������ʾ�̬��Ա 
	cout << corgi;
	Dog pug = Dog("pug the boss", 5);
	pug.ndog_plus();
	Dog *ptr_pug = &pug;
	cout << pug;
	
	cout << "Dog nums: " << ptr_pug->ndog << ", same as " << pug.ndog << endl;//����ָ�롢������ʾ�̬��Ա
	Cat catty = Cat("cute catty", 2, corgi);
	cout << catty;
	return 0;
}



