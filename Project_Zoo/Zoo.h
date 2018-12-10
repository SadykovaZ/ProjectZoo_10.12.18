#pragma once
#include"Animal.h"
#include<vector>
#include<fstream>
using namespace std;
class Zoo
{	
	vector<unique_ptr<Animal>>animals;
	string city;
	string zooName;
public:
	Zoo(string city, string zooName);
	void setZooName(string zooName);
	void setCity(string city);

	string getZooName()const { return zooName; }
	string getCity() const { return city; }
	
	
	void addAnimal(Animal* animal);
	void removeAnimal(Animal* animal);

	bool removeAnimalById(int id);

	Animal& operator[](int index)
	{
		return *animals[index];
	}
	const Animal& operator[](int index) const
	{
		return *animals[index];
	}

	Animal& getAnimal(int index);
	int getCountOfAnimals() const { return animals.size(); }

	Animal* getAnimalById(int id);
	const Animal* getAnimalById(int id) const;

	string rollCall()const;
	void info() const;	
};

