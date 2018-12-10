#pragma once
#include "Animal.h"
class Cat :
	public Animal
{
	string breed;
	
public:
	Cat(string name, string color, int age, string breed);
	Cat() = default;
	void setBreed(string breed);
	

	string getBreed() const { return breed; }
	

	void getInfo()const override;
	string voice() const override;	

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

