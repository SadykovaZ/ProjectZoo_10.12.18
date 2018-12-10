#pragma once
#pragma once
#include "Human.h"

class Employee abstract :
	public Human
{
	static int idSeq;
	unsigned int workYears;
	unsigned int id;
public:
	Employee(string name, int age, string sex, int workYears);
	Employee();
	void setWorkYears(int workYears);
	unsigned int getWorkYears()const { return workYears; }

	void info()const override;
	virtual double getSalary()const = 0;
	unsigned int getId()const { return id; }
	string getPosition() const { return (string(typeid(*this).name()).substr(6)); }

	virtual string getStringFileInfo()const;
	virtual void readStringInfo(string &str);
};