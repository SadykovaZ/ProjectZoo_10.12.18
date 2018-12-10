#pragma once
#include "Employee.h"
class Veterinarian
	:public Employee
{
	bool anesthesiologySkill;
	bool surgerySkill;
	bool ophthalmologySkill;
public:

	Veterinarian(string name, int age, string sex, int workYears, bool anesthesiologySkill, bool surgerySkill, bool ophthalmologySkill);
	Veterinarian() = default;

	void setAnesthesiologySkill(bool anesthesiologySkill);
	void setSurgerySkill(bool surgerySkill);
	void setOphthalmologySkill(bool ophthalmologySkill);

	bool getAnesthesiologySkill() const { return anesthesiologySkill; }
	bool getSurgerySkill()const { return surgerySkill; }
	bool getOphthalmologySkill() const { return ophthalmologySkill; }
	

	void info()const override;

	double getSalary()const override;

	string getStringFileInfo()const override;
	void readStringInfo(string &str)override;
};

