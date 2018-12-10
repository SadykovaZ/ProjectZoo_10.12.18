#pragma once
#include "Employee.h"
#include <vector>

using namespace std;

class Organization
{
	string name;
	vector<unique_ptr<Employee>>employees;
	int baseSalary;
public:
	void setName(string name);
	void setBaseSalary(int baseSalary);
	int getBaseSalary()const { return baseSalary; }
	string getName()const { return name; }
	Organization(string name, int baseSalary);
	void addEmployee(Employee* employee);
	void delEmployee(Employee* employee);
	void getInfo()const;
	double getSalaryFund()const;
	bool removeEmployeeById(int id);
	int getCountOfEmployee()const { return employees.size(); }
	Employee& operator [](int index) {
		return *employees[index];
	}
	const Employee& operator [](int index) const {
		return *employees[index];
	}
	
	Employee* getEmpById(int id); 
	const Employee* getEmpById(int id) const;

	
};