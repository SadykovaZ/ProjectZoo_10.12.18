#pragma once
#include "Animal.h"
class Elephant :
	public Animal
{
	int trunkLength;
	bool hasTusk; //наличие бивня
public:
	Elephant(string name, string color, int age, int trunkLength, bool hasTusk);
	Elephant() = default;
	void setTrunkLength(int trunkLength);
	void setHasTusk(bool hasTusk);

	int getTrunkLength() const { return trunkLength; }
	bool getHasTusk() const { return hasTusk; }

	void getInfo() const override;
	string voice() const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
	
};

