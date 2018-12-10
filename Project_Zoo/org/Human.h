#pragma once
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human// abstract
{
	string name;
	int age;
	string sex;
public:
	Human(string name, int age, string sex);
	void setName(string name);
	void setAge(int age);
	void setSex(string sex);

	string getName()const { return name; }
	int getAge()const { return age; }
	string getSex()const { return sex; }

	virtual void info()const;

	
};