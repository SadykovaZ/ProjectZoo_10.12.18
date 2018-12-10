#pragma once
#include <string>
#include<iostream>
using namespace std;
class Animal abstract
{
	string name;
	string color;
	int age;
	int id;
	static int idSeq;
public:
	Animal(string name, string color, int age);
	Animal();
	void setName(string name);
	void setColor(string color);
	void setAge(int age);

	string getName() const { return name; }
	string getColor() const { return color; }
	int getAge() const { return age; }
	
	virtual void getInfo() const;
	virtual string voice() const = 0;

	int getId() const { return id; }
	string getPosition() const { return (string(typeid(*this).name()).substr(6)); }

	virtual string getStringFileInfo()const;
	virtual void readStringInfo(string &str);
};

