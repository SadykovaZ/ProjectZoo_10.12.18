#pragma once
#include "Animal.h"
class Kangaroo :
	public Animal
{
	unsigned int bagSize;
public:
	Kangaroo(string name, string color, int age, int bagSize);
	Kangaroo() = default;
	void setBagSize(int bagSize);
	unsigned int getBagSize() const { return bagSize; }
	void getInfo() const override;
	string voice() const override;	

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

