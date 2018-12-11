#include "Elephant.h"
Elephant::Elephant(string name, string color, int age, int trunkLength, bool hasTusk)
	:Animal(name, color, age)
{
	this->trunkLength = trunkLength;
	this->hasTusk = hasTusk;
}
void Elephant::setTrunkLength(int trunkLength)
{
	this->trunkLength = trunkLength;
}
void Elephant::setHasTusk(bool hasTusk)
{
	this->hasTusk = hasTusk;
}
void Elephant::getInfo() const
{
	Animal::getInfo();
	cout << "\nДлина хобота: " << trunkLength;
	cout << "\nНаличие бивней: " << boolChange(getHasTusk()) << endl;
	cout << "\n-------------------------------------\n";

	
}
string Elephant::voice() const
{
	return string("Тууууу");
}

string Elephant::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += to_string(trunkLength);
	res += ';';
	res += to_string(hasTusk);
	//res += ';';
	return res;
}

void Elephant::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	trunkLength = stoi(res.substr(0, res.find(';')));
	hasTusk = res[res.size() - 2];
}

string Elephant::boolChange(bool a) const
{
	string res;
	if (a == 1)
		return res = "Да";
	else
		return res = "Нет";
}
