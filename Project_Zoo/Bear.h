#pragma once
#include"Animal.h"
class Bear:
	public Animal
{
	string type;
public:
	Bear(string name, string color, int age, string type);
	Bear() = default;
	void setType(string type);

	string getType() const { return type; }
	
	void getInfo()const override;
	string voice() const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

