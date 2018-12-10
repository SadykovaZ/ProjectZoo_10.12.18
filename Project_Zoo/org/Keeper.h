#pragma once
#include "Employee.h"
class Keeper
	:public Employee
{
	bool attentiveness;
public:
	Keeper(string name, int age, string sex, int workYears, bool attentiveness);
	Keeper() = default;

	void setAttentiveness(bool attentiveness);
	bool getAttentiveness() const { return attentiveness; }

	void info()const override;

	double getSalary()const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &str)override;
};

