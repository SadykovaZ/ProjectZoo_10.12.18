#include "Organization.h"

void Organization::setName(string name)
{
	this->name = name;
}

void Organization::setBaseSalary(int baseSalary)
{
	this->baseSalary = baseSalary;
}

Organization::Organization(string name, int baseSalary)
{
	this->name = name;
	this->baseSalary = baseSalary;
}

void Organization::addEmployee(Employee * employee)
{
	employees.push_back(unique_ptr<Employee>(employee));
}

void Organization::delEmployee(Employee * employee)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i].get() == employee) {
			employees.erase(begin(employees) + i);
			return;
		}
	}
}

void Organization::getInfo() const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i]->info();
		cout << "Зарплата: " << baseSalary+employees[i]->getSalary()*baseSalary << endl;
		cout << "\n-----------------------------\n";
	}
}

double Organization::getSalaryFund() const
{
	double res = 0
		;
	for (size_t i = 0; i < employees.size(); i++)
	{
		res += employees[i]->getSalary()*baseSalary;
	}
	return res;
}

bool Organization::removeEmployeeById(int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id) {
			employees.erase(begin(employees) + i);
			return true;
		}
	}
	return false;
}


Employee * Organization::getEmpById(int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id)
		{
			return employees[i].get();
		}
	}
	return nullptr;
}

const Employee * Organization::getEmpById(int id) const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id)
		{
			return employees[i].get();
		}
	}
	return nullptr;
}

