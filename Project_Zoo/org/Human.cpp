#include "Human.h"

Human::Human(string name, int age, string sex)
{
	this->name = name;
	this->age = age;

	this->sex = sex;
}

void Human::setName(string name)
{
	this->name = name;
}

void Human::setAge(int age)
{

	this->age = age;
}

void Human::setSex(string sex)
{
	this->sex = sex;
}

void Human::info() const
{
	cout << "Имя: " << name << "\nВозвраст: " << age << "\nПол: " << sex << endl;
}

