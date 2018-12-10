#pragma once
#include"Animal.h"
class Giraffe:
	public Animal
{
	unsigned int neckLength;
public:
	Giraffe(string name, string color, int age, int neckLength);
	Giraffe() = default;
	void setNeckLength(int neckLength);
		
	unsigned int getNeckLength() const { return neckLength; }

	void getInfo()const override;
	string voice() const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
	
};

