//Inheritance
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;
};
class Cat :public Animal
{
public:
	void sound()
	{
		cout << "ּÿף" << endl;
	}
};
class Dog :public Animal
{
public:
	void sound()
	{
		cout << "ֳאג" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Cat tom;
	tom.sound();

	Dog hatico;
	hatico.sound();
}