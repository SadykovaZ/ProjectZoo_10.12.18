#include "Kangaroo.h"
Kangaroo::Kangaroo(string name, string color, int age, int bagSize)
	:Animal(name, color, age)
{
	this->bagSize = bagSize;
}
void Kangaroo::setBagSize(int bagSize)
{
	this->bagSize = bagSize;
}
void Kangaroo::getInfo() const
{
	Animal::getInfo();
	cout << "\nРазмер сумки: " << bagSize << endl;	
	cout << "-------------------------------------\n";

}
string Kangaroo::voice() const
{
	return string("Щелк");
}

string Kangaroo::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += to_string(bagSize);
	//res += ';';
	return res;
}

void Kangaroo::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	bagSize = stoi(res.substr(0, res.find(';')));
}
