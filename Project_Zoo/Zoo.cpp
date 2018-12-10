#include "Zoo.h"
Zoo::Zoo(string city, string zooName)
{
	this->city = city;
	this->zooName = zooName;
}

void Zoo::setZooName(string zooName)
{
	this->zooName = zooName;
}

void Zoo::setCity(string city)
{
	this->city = city;
}

void Zoo::addAnimal(Animal * animal)
{
	animals.push_back(unique_ptr<Animal>(animal));
}

void Zoo::removeAnimal(Animal* animal)
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		if (animals[i].get() == animal)
		{
			animals.erase(begin(animals) + i);
			return;
		}
	}
}
bool Zoo::removeAnimalById(int id)
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		if (animals[i]->getId() == id) {
			animals.erase(begin(animals) + i);
			return true;
		}
	}
	return false;
}
Animal& Zoo::getAnimal(int index)
{	
	return *animals[index];
}
Animal * Zoo::getAnimalById(int id)
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		if (animals[i]->getId() == id)
		{
			return animals[i].get();
		}
	}
	return nullptr;
}
const Animal * Zoo::getAnimalById(int id) const
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		if (animals[i]->getId() == id)
		{
			return animals[i].get();
		}
	}
	return nullptr;
}
string Zoo::rollCall() const
{
	string res;
	for (size_t i = 0; i < animals.size(); i++)
	{
		string tmp = typeid(*animals[i]).name();
		tmp = tmp.substr(6);
		res += tmp + " ";
		res += animals[i]->getName() + " говорит ";
		res += animals[i]->voice() += "\n";
	}
	return res;
}
void Zoo::info() const
{
	
	cout << "Зоопарк " << zooName << " города " << city << endl;
	for (size_t i = 0; i < animals.size(); i++)
	{
		animals[i]->getInfo();		
	}
	
}
