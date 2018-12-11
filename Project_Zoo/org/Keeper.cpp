#include "Keeper.h"

Keeper::Keeper(string name, int age, string sex, int workYears, bool attentiveness)
	:Employee(name, age, sex, workYears)
{
	setAttentiveness(attentiveness);
}

void Keeper::setAttentiveness(bool attentiveness)
{
	this->attentiveness = attentiveness;
}

void Keeper::info() const
{
	Employee::info();

	cout << "Внимательность: " << boolalpha << boolChange(getAttentiveness()) << endl;
}

double Keeper::getSalary() const
{
	double coef = getWorkYears()*0.25;
	coef += attentiveness * 0.1;

	return coef;
}

string Keeper::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
//	res += ';';
	res += to_string(getAttentiveness());
	res += ';';
	return res;
}

void Keeper::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
	attentiveness = res[res.size() - 2];
}

string Keeper::boolChange(bool a) const
{
	string res;
	if (a == 1)
		return res = "Да";
	else
		return res = "Нет";
}
