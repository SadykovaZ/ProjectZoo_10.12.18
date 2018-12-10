#pragma once
#include "Employee.h"

 class Gardener:
	 public Employee
{
	 bool creativeSkills;
public:
	Gardener(string name, int age, string sex, int workYears, bool creativeSkills);
	Gardener() = default;
	void setCreativeSkills(bool creativeSkills);
	bool getCreativeSkills() const { return creativeSkills; }

	void info()const override;

	double getSalary()const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &str)override;
};

