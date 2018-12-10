#pragma once
#include"Animal.h"
class Monkey:
	public Animal
{
	string type;
public:
	Monkey(string name, string color, int age, string type);
	Monkey() = default;
	void setType(string type);	

	string getType() const { return type; }
	
	void getInfo()const override;
	string voice() const override ;	

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

