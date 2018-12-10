#include "Cat.h"

Cat::Cat(string name, string color, int age, string breed)
	:Animal(name,  color,  age)
{
	this->breed = breed;
	
}
void Cat::setBreed(string breed)
{
	this->breed = breed;
}

void Cat::getInfo() const
{
	Animal::getInfo();
	cout << "\nѕорода семейста кошачих: " << breed<<endl;	
	cout << "-------------------------------------\n";

}
string Cat::voice() const
{
	return string("ћ€у");
}

string Cat::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += breed;
	//res += ';';	
	return res;
}

void Cat::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	
	breed = res;
	
}
