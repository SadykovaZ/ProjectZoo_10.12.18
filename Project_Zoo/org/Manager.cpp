#include "Manager.h"


Manager::Manager(string name, int age, string sex, int workYears, bool communicationSkills, bool hasEdu)
	:Employee(name, age, sex, workYears)
{
	setCommunicationSkills(communicationSkills);
	setHasEdu(hasEdu);
}

void Manager::setCommunicationSkills(bool communicationSkills)
{
	this->communicationSkills = communicationSkills;
}

void Manager::setHasEdu(bool hasEdu)
{
	this->hasEdu = hasEdu;
}

void Manager::info() const
{
	Employee::info();
	cout << "Коммуникативные навыки: " << boolalpha << boolChange(getCommunicationSkills()) << endl;
	cout << "Высшее образование: " << boolalpha << boolChange(getHasEdu()) << endl;
}

double Manager::getSalary() const
{
	double coef = communicationSkills * 0.05;
	coef += hasEdu * 0.03;
	coef += getWorkYears()*0.05;

	return coef;
}

string Manager::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
	//res += ';';
	res += to_string(getCommunicationSkills()) + ";";
	res += to_string(getHasEdu());
	res += ';';
	return res;
}

void Manager::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
	communicationSkills = res[res.size() - 2];
	hasEdu = res[res.size() - 2];
}

string Manager::boolChange(bool a) const
{
	string res;
	if (a == 1)
		return res = "Да";
	else
		return res = "Нет";
}
