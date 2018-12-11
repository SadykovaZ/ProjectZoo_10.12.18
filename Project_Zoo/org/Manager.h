#pragma once
#include "Employee.h"
class Manager
	:public Employee
{
	bool communicationSkills;
	bool hasEdu;
public:
	Manager(string name, int age, string sex, int workYears, bool communicationSkills, bool hasEdu);
	Manager() = default;

	void setCommunicationSkills(bool communicationSkills);
	void setHasEdu(bool hasEdu);

	bool getCommunicationSkills() const { return communicationSkills; }
	bool getHasEdu()const { return hasEdu; }

	void info()const override;

	double getSalary()const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &str)override;
	string boolChange(bool a) const;

};

