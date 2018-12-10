#pragma once
#include "Employee.h"

class Director :
	public Employee
{
public:
	Director(string name, int age, string sex, int workYears);
	Director() = default;
	double getSalary()const override;	
};