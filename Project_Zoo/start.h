#pragma once
#include "org/Organization.h"
#include "org/Director.h"
#include "org/Manager.h"
#include "org/Keeper.h"
#include "org/Veterinarian.h"
#include "org/Gardener.h"

#include"Zoo.h"
#include"Cat.h"
#include"Elephant.h"
#include"Kangaroo.h"
#include"Bear.h"
#include"Giraffe.h"
#include"Monkey.h"

#include <fstream>
#include <iostream>
#include <Windows.h>
#include <conio.h>



using namespace std;

class start
{

public:
	Organization org;
	Zoo z;
	start();
	void begin();

	~start();
	void saveToFile()const;
	void loadFromFile();
private:
	void startMenu();
	void mainMenu();

#pragma region Zoo
	void mainMenuZoo();
	void addAnimalMenu();
	void removeAnimalMenu();
	void showAnimalInfo()const;

	void setZooNameMenu();
	void setCityNameMenu();
	void setAnimalInfoMenu();
	void showShortAnimalInfo() const;
	
	void editAnimalMenu(Animal* animal);
	void editAnimalInfo(Animal* animal);
#pragma endregion

#pragma region Org

	void mainMenuOrg();
	void addEmpMenu();
	void removeEmpMenu();
	void showOrganizationInfo()const;

	void setOrgNameMenu();
	void setSalaryMenu();
	void setEmpInfoMenu();
	void showShortOrgInfo() const;
	
	void editEmpMenu(Employee* emp);
	void editEmpInfo(Employee* emp);
	void changePosition(Employee* emp);

#pragma endregion

	void clearScreen()const { system("cls"); }
	void pause()const { system("pause"); }

};
