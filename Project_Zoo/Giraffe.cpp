#include "Giraffe.h"
Giraffe::Giraffe(string name, string color, int age, int neckLength)
	:Animal(name, color, age)
{
	this->neckLength = neckLength;
}

void Giraffe::setNeckLength(int neckLength)
{
	this->neckLength = neckLength;

}

void Giraffe::getInfo() const
{
	Animal::getInfo();
	cout << "\nÄëèííà øåè æèðàôà: " << neckLength << endl;
	cout << "-------------------------------------\n";

	
}

string Giraffe::voice() const
{
	return string("Õõõõõõ");
}

string Giraffe::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += to_string(neckLength);
	//res += ';';
	return res;
}

void Giraffe::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	neckLength = stoi(res.substr(0, res.find(';')));
	
}
