#include "Gardener.h"

Gardener::Gardener(string name, int age, string sex, int workYears, bool creativeSkills)
	:Employee(name, age, sex, workYears)
{
	setCreativeSkills(creativeSkills);
}

void Gardener::setCreativeSkills(bool creativeSkills)
{
	this->creativeSkills = creativeSkills;
}

void Gardener::info() const
{
	Employee::info();
	cout << "Творческие навыки: " << boolalpha << boolChange(getCreativeSkills()) << endl;
}

double Gardener::getSalary() const
{
	double coef = getWorkYears()*0.15;
	coef += creativeSkills * 0.3;

	return coef;
}

string Gardener::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
	res += to_string(getCreativeSkills());
	res += ';';

	return res;
}

void Gardener::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
	creativeSkills = res[res.size() - 2];
}

string Gardener::boolChange(bool a) const
{
	string res;
	if (a == 1)
		return res = "Да";
	else
		return res = "Нет";
}
