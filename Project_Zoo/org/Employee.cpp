#include "Employee.h"

int Employee::idSeq = 0;

Employee::Employee(string name, int age, string sex, int workYears)
	:Human(name, age, sex)
{
	this->id = ++idSeq;
	this->workYears = workYears;
}

Employee::Employee() :Human("", 0, "") { id = ++idSeq; }

void Employee::setWorkYears(int workYears)
{
	this->workYears = workYears;
}

void Employee::info() const
{
	string emp = string(typeid(*this).name()).substr(6);
	if (emp == "Director") emp = "Директор";
	else if (emp == "Gardener") emp = "Садовник";
	else if (emp == "Keeper") emp = "Смотритель";
	else if (emp == "Manager") emp = "Менеджер";
	else if (emp == "Veterinarian") emp = "Ветеринар";
	cout << "Должность: " << emp << endl;
	Human::info();
	cout << "Опыт работы: " << workYears << endl;
}

string Employee::getStringFileInfo() const
{
	char d = ';';
	string res = typeid(*this).name();
	res = res.substr(6) + d;
	res += getName() += d;
	res += to_string(getAge()) += d;
	res += getSex() += d;
	res += to_string(getWorkYears()) += d;

	return res;
}

void Employee::readStringInfo(string & str)
{
	string info[4];
	for (size_t i = 0; i < 4; i++)
	{
		info[i] = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->setName(info[0]);
	this->setAge(stoi(info[1]));
	this->setSex(info[2]);
	this->setWorkYears(stoi(info[3]));
}
