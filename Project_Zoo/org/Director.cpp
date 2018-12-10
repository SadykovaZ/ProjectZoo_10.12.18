#include "Director.h"

Director::Director(string name, int age, string sex, int workYears)
	:Employee(name, age, sex, workYears)
{
}


double Director::getSalary() const
{
	double coef = 2;
	return coef;
}
