#include "start.h"
#include<iomanip>

start::start()
	:org("", 0), z("", "")
{
	try {
		loadFromFile();
	}
	catch (exception&e)
	{
		cout << e.what() << endl;
		pause();
	}
}

void start::begin()
{
	cout << "����� ����������!\n";

	Sleep(2000);
	clearScreen();

	if (org.getName() == "" || z.getZooName() == "")
		startMenu();
	mainMenu();
}
start::~start()
{
	saveToFile();
}
void start::saveToFile() const
{
	ofstream fileOrg("org.txt");

	fileOrg << org.getName() << ";"
		<< to_string(org.getBaseSalary()) << "\n";
	for (size_t i = 0; i < org.getCountOfEmployee(); i++)
	{
		fileOrg << org[i].getStringFileInfo();
		if (i != org.getCountOfEmployee() - 1) fileOrg << endl;
	}
	fileOrg.close();

	ofstream fileZoo("zoo.txt");
	fileZoo << z.getZooName() << ";"
		<< z.getCity() << "\n";

	for (size_t i = 0; i < z.getCountOfAnimals(); i++)
	{
		fileZoo << z[i].getStringFileInfo();
		if (i != z.getCountOfAnimals() - 1) fileZoo << endl;
	}
	fileZoo.close();
}
void start::loadFromFile()
{
	{
		ifstream file("org.txt");
		if (!file)
			throw exception("���������� ������� ����!");
		string s;
		getline(file, s);
		org.setName(s.substr(0, s.find(';')));
		s = s.substr(s.find(';') + 1);
		if (s[s.size() - 1] == ';')	s.pop_back();
		org.setBaseSalary(stoi(s));
		while (!file.eof())
		{
			getline(file, s);
			string type = s.substr(0, s.find(';'));
			Employee*emp = nullptr;
			if (type == "Director") {
				emp = new Director;
			}
			else if (type == "Gardener") {
				emp = new Gardener;
			}
			else if (type == "Keeper") {
				emp = new Keeper;
			}
			else if (type == "Manager")
			{
				emp = new Manager;
			}
			else if (type == "Veterinarian")
			{
				emp = new Veterinarian;
			}
			s = s.substr(s.find(';') + 1);
			emp->readStringInfo(s);
			org.addEmployee(emp);
		}
		file.close();
	}
	{
		ifstream file("zoo.txt");
		if (!file)
			throw exception("���������� ������� ����!");
		string s;
		getline(file, s);
		z.setZooName(s.substr(0, s.find(';')));
		s = s.substr(s.find(';') + 1);
		if (s[s.size() - 1] == ';')	s.pop_back();
		z.setCity(s.substr(0, s.find(';')));
		s = s.substr(s.find(';') + 1);
		if (s[s.size() - 1] == ';')	s.pop_back();
		while (!file.eof())
		{
			getline(file, s);
			string type = s.substr(0, s.find(';'));
			Animal*anim = nullptr;
			if (type == "Bear") {
				anim = new Bear;
			}
			else if (type == "Cat") {
				anim = new Cat;
			}
			else if (type == "Elephant") {
				anim = new Elephant;
			}
			else if (type == "Giraffe") {
				anim = new Giraffe;
			}
			else if (type == "Kangaroo") {
				anim = new Kangaroo;
			}
			else if (type == "Monkey") {
				anim = new Monkey;
			}

			s = s.substr(s.find(';') + 1);
			anim->readStringInfo(s);
			z.addAnimal(anim);
		}
		file.close();
	}
}
void start::startMenu()
{
	clearScreen();

	cout << "����� ����������!";
	Sleep(800);
	//org
	if (org.getName() == "") {
		this->setOrgNameMenu();
		this->setSalaryMenu();
	}
	//zoo
	if (z.getZooName() == "") {
		this->setZooNameMenu();
		this->setCityNameMenu();
	}
}
void start::mainMenuOrg()
{
	int choice = 0;
	while (1)
	{
		clearScreen();
		cout << "�������� �����������: " << org.getName();
		cout << "\n��������: " << org.getBaseSalary();
		cout << "\n���������� �����������: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. �������� ������ ����������\n\
		2. ������� ����������\n\
		3. ���������� �� �����������\n\
                4. ���������� �� �����������\n\
		0. ����� �� ��������� ����� ������\n"
			;
		cin >> choice;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "����� ������� ������ �����!" << endl;
			pause();
			clearScreen();
			continue;
		}
		switch (choice)
		{
		case 0: clearScreen();
			return;
			break;
		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showOrganizationInfo();
			pause();
			break;
		case 4:
			setEmpInfoMenu();
			pause();
			break;
		
		default:
			cout << "����������� �������\n������� ����� ������� ��� �����������\n";
			pause();
			clearScreen();
			break;
		}
	}
	
	pause();
	clearScreen();
}
void start::mainMenuZoo()
{
	clearScreen();
	int choice = 0;
	while (1) {
		
		cout << "��� ��������: " << z.getZooName();
		cout << "\n�����: " << z.getCity();
		cout << "\n���������� ��������: " << z.getCountOfAnimals();
		cout << "\n\n----------------------------------------------------------\n\n";
		cout << "\
		1. �������� ����� ��������\n\
		2. �������� ���������\n\
		3. �������� ���������� � ��������\n\
                4. �������� ���������� � ��������\n\
		0. ����� �� ��������� ����� ������\n"
			;
		cin >> choice;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "����� ������� ������ �����!" << endl;
			pause();
			clearScreen();
			continue;
		}
		switch (choice)
		{
		case 0:clearScreen();
			return;
			break;
		case 1:
			addAnimalMenu();
			break;
		case 2:
			removeAnimalMenu();
			break;
		case 3:
			showAnimalInfo();
			pause();
			clearScreen();
			break;
		case 4:
			setAnimalInfoMenu();
			break;		
		default:
			cout << "������������ �������\n������� ����� ������ ����� ����������\n";
			pause();
			clearScreen();
			break;
		}
	}
	
	pause();
	clearScreen();
}
void start::addAnimalMenu()
{
	clearScreen();
	size_t ch;
	while (1) {
		
		cout << "�������� ��������\n";
		cout << "1. �������\n2. �����\n3. ����\n4. �����\n5. �������\n6. ��������\n0. ����� � �������� ����\n";
		cin >> ch;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "����� ������� ������ �����!" << endl;
			pause();
			clearScreen();
			continue;
		}
		if (ch > 6) {
			cout << "�������� �������\n";
			pause();
		}
		else
			break;

	}
	if (ch == 0)
		return;
	string name;
	string color;
	int age;
	clearScreen();
	cout << "������� ��� ���������\n";
	cin >> name;
	cout << "������� ���� ���������\n";
	cin >> color;
	cout << "������� ������� ���������\n";
	cin >> age;

	Animal*anim = nullptr;
	switch (ch)
	{
	case 1:
	{

		string type;
		cout << "������� ��� �������\n";
		cin >> type;
		anim = new Bear(name, color, age, type);
		break;
	}
	case 2:
	{
		string breed;

		cout << "������� ������\n";
		cin >> breed;
		anim = new Cat(name, color, age, breed);
		break;
	}
	case 3:
	{
		int trunkLength;
		bool hasTusk;
		cout << "������� ����� ������ (��)\n";
		cin >> trunkLength;
		cout << "���� �� � ����� �����? (1 - ��, 0 - ���)\n";
		cin >> hasTusk;
		anim = new Elephant(name, color, age, trunkLength, hasTusk);
		break;
	}
	case 4:
	{
		int neckLength;
		cout << "������� ����� ���\n";
		cin >> neckLength;
		anim = new Giraffe(name, color, age, neckLength);
		break;
	}
	case 5:
	{
		int bagSize;
		cout << "������� ������ �����\n";
		cin >> bagSize;
		anim = new Kangaroo(name, color, age, bagSize);
		break;
	}
	case 6:
	{
		string type;
		cout << "������� ��� ��������\n";
		cin >> type;
		anim = new Monkey(name, color, age, type);
		break;
	}
	}
	clearScreen();
	z.addAnimal(anim);
	cout << "�������� ���������!\n";
	pause();
}
void start::removeAnimalMenu()
{
	while (1) {
		clearScreen();
		cout << "�������� ID ��������� ��� ��������" << endl;
		showShortAnimalInfo();
		int ch;
		cin >> ch;
		if (!z.removeAnimalById(ch)) {
			cout << "�������� ID!\n";
			pause();
			continue;
		}
		cout << "�������� ���������!\n";
		pause();
		return;
	}
}
void start::showAnimalInfo() const
{
	clearScreen();
	z.info();	
}
void start::mainMenu()
{
	clearScreen();
	while (1)
	{
		
		cout << "�������� �����������: " << org.getName();
		cout << "\n��������: " << org.getBaseSalary();
		cout << endl << endl;
		cout << "��� ��������: " << z.getZooName();
		cout << "\n�����: " << z.getCity();
		cout << "\n\n-------------------------------------------------\n\n";

		cout << "1 - ���������� � �����������\n";
		cout << "2 - ���������� � ��������\n";
		cout << "3 - �������� �������� �����������\n";
		cout << "4 - �������� �������� ��������\n";
		cout << "5 - �������� ��������\n";
		cout << "6 - �������� �����\n";
		cout << "0 - ��������� � �����\n";
		int choice;
		cin >> choice;
		
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "����� ������� ������ �����!" << endl;			
			pause();
			clearScreen();
			continue;
		}		

		switch (choice)
		{
		case 0:
			return;
			break;
		case 1:
			mainMenuOrg();
			break;
		case 2:
			mainMenuZoo();
			break;
		case 3:
			this->setOrgNameMenu();
			clearScreen();
			break;
		case 4:
			this->setZooNameMenu();
			clearScreen();
			break;
		case 5:
			this->setSalaryMenu();
			clearScreen();
			break;
		case 6:
			this->setCityNameMenu();
			clearScreen();
			break;
		default:			
				cout << "����������� �������\n";
				pause();
				clearScreen();
				continue;			
			break;
		}
	}
}
void start::addEmpMenu()
{
	size_t ch;
	while (1) {
		clearScreen();
		cout << "�������� ���������\n";
		cout << "1. �������\n2. ����������\n3. ��������\n4. ��������\n5. ���������\n0. �������� ����\n";
		cin >> ch;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "����� ������� ������ �����!" << endl;
			pause();
			clearScreen();
			continue;
		}
		if (ch > 5) {
			cout << "����������� ���������\n";
			pause();
		}
		else
			break;
	}
	if (ch == 0)
		return;
	string name;
	int age;
	string sex;
	int exp;
	clearScreen();
	cout << "������� ��� ����������\n";
	cin >> name;
	cout << "������� �������� ����������\n";
	cin >> age;
	cout << "������� ��� ����������\n";
	cin >> sex;
	cout << "������� ���� ����������\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool creativeSkills;
		cout << "������� �� ���������� �����? (1 - ��, 0 - ���)\n";
		cin >> creativeSkills;
		emp = new Gardener(name, age, sex, exp, creativeSkills);
		break;
	case 2:
		bool attentiveness;
		cout << "��������������? (1 - ��, 0 - ���)\n";
		cin >> attentiveness;

		emp = new Keeper(name, age, sex, exp, attentiveness);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		bool communication;
		cout << "������� ������� �����������? (1 - ��, 0 - ���)\n" << endl;
		cin >> edu1;
		cout << "�����������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> communication;
		emp = new Manager(name, age, sex, exp, edu1, communication);
		break;
	case 5:
		bool anesthesiology;
		bool surgery;
		bool ophthalmology;
		cout << "�������� �� ��������� ���������� ��������: \n";
		cout << "��������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> anesthesiology;
		cout << "��������? (1 - ��, 0 - ���)\n" << endl;
		cin >> surgery;
		cout << "�������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> ophthalmology;

		emp = new Veterinarian(name, age, sex, exp, anesthesiology, surgery, ophthalmology);
		break;
	}
	clearScreen();
	org.addEmployee(emp);
	cout << "��������� ��������!\n";
	pause();
}
void start::removeEmpMenu()
{
	while (1) {
		clearScreen();
		cout << "�������� ID ��������� ��� ����������:" << endl;
		showShortOrgInfo();
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "�������� ID!\n";
			pause();
			continue;
		}
		cout << "�������� ������!\n";
		pause();
		return;
	}
}
void start::showOrganizationInfo() const
{
	clearScreen();
	org.getInfo();
}
void start::setZooNameMenu()
{
	clearScreen();
	cout << "������� �������� ��������\n";
	string name;
	cin >> name;
	z.setZooName(name);
}
void start::setCityNameMenu()
{
	clearScreen();
	cout << "������� �������� ������\n";
	string name;
	cin >> name;
	z.setCity(name);
}
void start::setAnimalInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortAnimalInfo();
		cout << "0- ��������� �����";
		cout << "\n������� ID ���������: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Animal *anim = z.getAnimalById(ch);

		if (anim == nullptr)
		{
			cout << "�������� ID\n";
			pause();
			continue;
		}
		editAnimalMenu(anim);
	}
}
void start::showShortAnimalInfo() const
{
	string ani;
	for (int i = 0; i < z.getCountOfAnimals(); i++)
	{
		ani = string(typeid(z[i]).name()).substr(6);
		if (ani == "Bear") ani = "�������"; else if (ani == "Cat") ani = "�����";
		else if (ani == "Elephant") ani = "����"; else if (ani == "Giraffe") ani = "�����";
		else if (ani == "Kangaroo") ani = "�������"; else if (ani == "Monkey") ani = "��������";

		cout << setw(3) << left << z[i].getId()

			<< setw(10) << left << ani
			<< setw(10) << left << z[i].getName() << endl;
	}
}

void start::editAnimalMenu(Animal * animal)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*animal).name()).substr(6) << endl;
		animal->getInfo();
		cout << "1. �������� ���������� � ��������\n";
		cout << "2. �������� ����������\n";
		cout << "0. Back\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editAnimalInfo(animal);
			break;
		case 2:
			z.removeAnimalById(animal->getId());
			cout << "�������� ���������!" << endl;
			pause();
			return;
			break;
		default:
			cout << "����������� �������";
			break;
		}
	}
}
void start::editAnimalInfo(Animal * animal)
{
	while (1)
	{
		clearScreen();
		animal->getInfo();
		int index = 0;
		cout << "\n�������� ����� ���������� ��������\n";
		cout << ++index << ". ���\n";
		cout << ++index << ". ����\n";
		cout << ++index << ". �������\n";

		int pos;
		if (typeid(*animal) == typeid(Bear))
		{
			pos = 1;
			cout << ++index << ". ��� �������\n";
		}
		else if (typeid(*animal) == typeid(Cat))
		{
			pos = 2;
			cout << ++index << ". ������ \n";


		}
		else if (typeid(*animal) == typeid(Elephant))
		{
			pos = 3;
			cout << ++index << ". ����� ������ (��) \n";
			cout << ++index << ". ���� �� �����? (1 - ��, 0 - ���) \n";

		}
		else if (typeid(*animal) == typeid(Giraffe))
		{
			pos = 4;
			cout << ++index << ". ����� ��� \n";
		}
		else if (typeid(*animal) == typeid(Kangaroo))
		{
			pos = 5;
			cout << ++index << ". ������ ����� \n";
		}
		else if (typeid(*animal) == typeid(Monkey))
		{
			pos = 6;
			cout << ++index << ". ��� �������� \n";
		}

		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "����������� �������!\n";
			pause();
			continue;
		}
		switch (ch)
		{
		case 0: return;
			break;
		case 1:
		{
			string name;
			cout << "\n ������� ����� ���: ";
			cin >> name;
			animal->setName(name);
			break;
		}
		case 2:
		{
			string color;
			cout << "\n ������� ����� �������: ";
			cin >> color;
			animal->setColor(color);
			break;
		}
		case 3:
		{
			int age;
			cout << "\n ������� ����� �������: ";
			cin >> age;
			animal->setAge(age);
			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 4)
				{
					cout << "������� ��� �������\n";
					string type;
					cin >> type;
					((Bear*)animal)->setType(type);
				}
				break;
			case 2:
				if (ch == 4)
				{
					cout << "������� ������\n";
					string breed;
					cin >> breed;
					((Cat*)animal)->setBreed(breed);
				}
				break;
			case 3:
				if (ch == 4)
				{
					cout << "������� ����� ������\n";
					int trunkLength;
					cin >> trunkLength;
					((Elephant*)animal)->setTrunkLength(trunkLength);
				}
				else
				{
					cout << "���� �� �����\n";
					bool hasTusk;
					cin >> hasTusk;
					((Elephant*)animal)->setHasTusk(hasTusk);
				}
				break;
			case 4:
				if (ch == 4)
				{
					cout << "������ ���\n";
					int neckLength;
					cin >> neckLength;
					((Giraffe*)animal)->setNeckLength(neckLength);
				}
				break;
			case 5:
				if (ch == 4)
				{
					cout << "������ �����\n";
					int bagSize;
					cin >> bagSize;
					((Kangaroo*)animal)->setBagSize(bagSize);
				}
				break;
			case 6:
				if (ch == 4)
				{
					cout << "��� ��������\n";
					string type;
					cin >> type;
					((Monkey*)animal)->setType(type);
				}
				break;

			}
		}
		break;
		}
	}
	pause();
}
void start::setOrgNameMenu()
{
	clearScreen();
	cout << "������� ��� �����������: \n";
	string name;
	cin >> name;
	org.setName(name);
}
void start::setSalaryMenu()
{
	clearScreen();
	cout << "������� ��������: \n";
	int sal;
	cin >> sal;
	org.setBaseSalary(sal);
}
void start::setEmpInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortOrgInfo();
		cout << "0- ��������� �����";
		cout << "\n�������� ID ���������: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "�������� ID!\n";
			pause();
			continue;
		}
		editEmpMenu(e);
	}
}
void start::showShortOrgInfo() const
{
	string emp;
	for (int i = 0; i < org.getCountOfEmployee(); i++)
	{
		emp = string(typeid(org[i]).name()).substr(6);
		if (emp == "Director") emp = "��������";
		else if (emp == "Gardener") emp = "��������";
		else if (emp == "Keeper") emp = "����������";
		else if (emp == "Manager") emp = "��������";
		else if (emp == "Veterinarian") emp = "���������";

		cout << setw(3) << left << org[i].getId()
			<< setw(10) << left << emp
			<< setw(10) << left << org[i].getName() << endl;
	}
}
void start::editEmpMenu(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*emp).name()).substr(6) << endl;
		emp->info();
		cout << "1. �������� ���������� � ����������\n";
		cout << "2. ������� ����������\n";
		cout << "3. �������� ������� ����������\n";
		cout << "0. �����\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmpInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "�������� ������!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
		default:
			cout << "����������� �������";
			break;
		}
	}
}
void start::editEmpInfo(Employee * emp)
{
	while (1)
	{
		clearScreen();
		emp->info();
		int index = 0;
		cout << "\n�������� ���������� ��� ���������: \n";
		cout << ++index << ". ���\n";
		cout << ++index << ". �������\n";
		cout << ++index << ". ���\n";
		cout << ++index << ". ���� ������\n";
		int pos;
		if (typeid(*emp) == typeid(Gardener))
		{
			pos = 1;
			cout << ++index << ". ���������� ������\n";
		}
		else if (typeid(*emp) == typeid(Keeper))
		{
			pos = 2;
			cout << ++index << ". ��������������\n";
		}
		else if (typeid(*emp) == typeid(Manager))
		{
			pos = 3;
			cout << ++index << ". ��������������� ������\n";
			cout << ++index << ". ������ �����������\n";

		}
		else if (typeid(*emp) == typeid(Veterinarian))
		{
			pos = 4;
			cout << ++index << ". ������\n";			
		}
		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "����������� ��������!\n";
			pause();
			continue;
		}
		switch (ch)
		{
		case 0: return;
			break;
		case 1:
		{
			string name;
			cout << "\n������� ����� ���: ";
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			int age;
			cout << "\n������� ������: ";
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			string sex;
			cout << "\n������� ���: ";
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			int exp;
			cout << "\n������� ���� ������: ";
			cin >> exp;
			emp->setWorkYears(exp);
			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 5)
				{
					cout << "������� ������� �� ���������� ������\n";
					bool creativeSkills;
					cin >> creativeSkills;
					((Gardener*)emp)->setCreativeSkills(creativeSkills);
				}
				break;
			case 2:
				if (ch == 5)
				{
					cout << "������������ ���������?\n";
					bool attentiveness;
					cin >> attentiveness;
					((Keeper*)emp)->setAttentiveness(attentiveness);
				}
				break;
			case 3:
				if (ch == 5)
				{
					cout << "������� �� ��������������� ������\n";
					bool commSkills;
					cin >> commSkills;
					((Manager*)emp)->setCommunicationSkills(commSkills);
				}
				else
				{
					cout << "���� �� ������ �����������\n";
					bool hasEdu;
					cin >> hasEdu;
					((Manager*)emp)->setHasEdu(hasEdu);
				}
				break;
			case 4:
				if (ch == 5)
				{
					cout << "���� �� ��������� ������:\n";
					bool anastSkills;
					bool surgSkills;
					bool ophSkills;
					cout << "���������: ";
					cin >> anastSkills;
					cout << "��������: ";
					cin >> surgSkills;
					cout << "�������������: ";
					cin >> ophSkills;
					((Veterinarian*)emp)->setAnesthesiologySkill(anastSkills);
					((Veterinarian*)emp)->setSurgerySkill(surgSkills);
					((Veterinarian*)emp)->setOphthalmologySkill(ophSkills);
				}
				break;
			}
		}
		break;
		}
	}
	pause();
}
void start::changePosition(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << "�������� ����� ������� ��� ��������� " << emp->getPosition() << " " << emp->getName() << endl;
		cout << "1. ��������\n";
		cout << "2. ��������\n";
		cout << "3. ����������\n";
		cout << "4. ��������\n";
		cout << "5. ���������\n";
		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "����������� �������\n";
			pause();
			continue;
		}
		Employee *e = nullptr;
		switch (ch)
		{
		case 1:
			e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());

			break;
		case 2:
			e = new Gardener(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);

			break;
		case 3:
			e = new Keeper(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);

			break;
		case 4:
			e = new Manager(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 5:
			e = new Veterinarian(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0, 0);
			break;
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		return;
	}
}