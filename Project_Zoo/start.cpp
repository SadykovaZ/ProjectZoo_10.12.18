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
	cout << "Добро пожаловать!\n";

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
			throw exception("Невозможно открыть файл!");
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
			throw exception("Невозможно открыть файл!");
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

	cout << "Добро пожаловать!";
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
		cout << "Название организации: " << org.getName();
		cout << "\nЗарплата: " << org.getBaseSalary();
		cout << "\nКоличество сотрудников: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. Добавить нового сотрудника\n\
		2. Удалить сотрудника\n\
		3. Информация по организации\n\
                4. Информация по сотрудникам\n\
		0. Выход на начальный экран выбора\n"
			;
		cin >> choice;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "Можно вводить только цифры!" << endl;
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
			cout << "Неизвестная команда\nНажмити любую клавишу для продолжения\n";
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
		
		cout << "Имя зоопарка: " << z.getZooName();
		cout << "\nГород: " << z.getCity();
		cout << "\nКоличество животных: " << z.getCountOfAnimals();
		cout << "\n\n----------------------------------------------------------\n\n";
		cout << "\
		1. Добавить новое животное\n\
		2. Животное переехало\n\
		3. Показать информацию о животных\n\
                4. Изменить информацию о животных\n\
		0. Выход на начальный экран выбора\n"
			;
		cin >> choice;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "Можно вводить только цифры!" << endl;
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
			cout << "Неправильная команда\nнажмите любую кнопку чтобы продолжить\n";

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
		
		cout << "Выберите животное\n";
		cout << "1. Медведь\n2. Кошка\n3. Слон\n4. Жираф\n5. Кенгуру\n6. Обезьяна\n0. Выход в основное меню\n";
		cin >> ch;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "Можно вводить только цифры!" << endl;
			pause();
			clearScreen();
			continue;
		}
		if (ch > 6) {
			cout << "Неверная позиция\n";
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
	cout << "Введите имя животного\n";
	cin >> name;
	cout << "Введите цвет животного\n";
	cin >> color;
	cout << "Введите возраст животного\n";
	cin >> age;

	Animal*anim = nullptr;
	switch (ch)
	{
	case 1:
	{

		string type;
		cout << "Введите вид медведя\n";
		cin >> type;
		anim = new Bear(name, color, age, type);
		break;
	}
	case 2:
	{
		string breed;

		cout << "Введите породу\n";
		cin >> breed;
		anim = new Cat(name, color, age, breed);
		break;
	}
	case 3:
	{
		int trunkLength;
		bool hasTusk;
		cout << "Введите длину хобота (см)\n";
		cin >> trunkLength;
		cout << "Есть ли у слона бивни? (1 - да, 0 - нет)\n";
		cin >> hasTusk;
		anim = new Elephant(name, color, age, trunkLength, hasTusk);
		break;
	}
	case 4:
	{
		int neckLength;
		cout << "Введите длину шеи\n";
		cin >> neckLength;
		anim = new Giraffe(name, color, age, neckLength);
		break;
	}
	case 5:
	{
		int bagSize;
		cout << "Введите размер сумки\n";
		cin >> bagSize;
		anim = new Kangaroo(name, color, age, bagSize);
		break;
	}
	case 6:
	{
		string type;
		cout << "Введите вид обезьяны\n";
		cin >> type;
		anim = new Monkey(name, color, age, type);
		break;
	}
	}
	clearScreen();
	z.addAnimal(anim);
	cout << "Животное добавлено!\n";
	pause();
}
void start::removeAnimalMenu()
{
	while (1) {
		clearScreen();
		cout << "Выберите ID животного для переезда" << endl;
		showShortAnimalInfo();
		int ch;
		cin >> ch;
		if (!z.removeAnimalById(ch)) {
			cout << "Неверный ID!\n";
			pause();
			continue;
		}
		cout << "Животное переехало!\n";
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
		
		cout << "Название организации: " << org.getName();
		cout << "\nЗарплата: " << org.getBaseSalary();
		cout << endl << endl;
		cout << "Имя зоопарка: " << z.getZooName();
		cout << "\nГород: " << z.getCity();
		cout << "\n\n-------------------------------------------------\n\n";

		cout << "1 - Информация о сотрудниках\n";
		cout << "2 - Информация о животных\n";
		cout << "3 - Изменить название организации\n";
		cout << "4 - Изменить название Зоопарка\n";
		cout << "5 - Изменить зарплату\n";
		cout << "6 - Изменить город\n";
		cout << "0 - Сохранить и выйти\n";
		int choice;
		cin >> choice;
		
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "Можно вводить только цифры!" << endl;			
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
				cout << "Неизвестная команда\n";
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
		cout << "Выберити должность\n";
		cout << "1. Садовод\n2. Смотритель\n3. Директор\n4. Менеджер\n5. Ветеринар\n0. Основное меню\n";
		cin >> ch;
		if (cin.fail()) {
			clearScreen();
			cin.clear();
			cin.ignore();
			cout << "Можно вводить только цифры!" << endl;
			pause();
			clearScreen();
			continue;
		}
		if (ch > 5) {
			cout << "Неизвестная должность\n";
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
	cout << "Введите имя сотрудника\n";
	cin >> name;
	cout << "Введите возвраст сотрудника\n";
	cin >> age;
	cout << "Введите пол сотрудника\n";
	cin >> sex;
	cout << "Введите опыт сотрудника\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool creativeSkills;
		cout << "Имеется ли творческий стиль? (1 - да, 0 - нет)\n";
		cin >> creativeSkills;
		emp = new Gardener(name, age, sex, exp, creativeSkills);
		break;
	case 2:
		bool attentiveness;
		cout << "Внимательность? (1 - да, 0 - нет)\n";
		cin >> attentiveness;

		emp = new Keeper(name, age, sex, exp, attentiveness);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		bool communication;
		cout << "Наличие высшего образования? (1 - да, 0 - нет)\n" << endl;
		cin >> edu1;
		cout << "Коммуникативность? (1 - да, 0 - нет)\n" << endl;
		cin >> communication;
		emp = new Manager(name, age, sex, exp, edu1, communication);
		break;
	case 5:
		bool anesthesiology;
		bool surgery;
		bool ophthalmology;
		cout << "Обладает ли сотрудник следующими навыками: \n";
		cout << "анестезиологии? (1 - да, 0 - нет)\n" << endl;
		cin >> anesthesiology;
		cout << "хирургия? (1 - да, 0 - нет)\n" << endl;
		cin >> surgery;
		cout << "офтальмология? (1 - да, 0 - нет)\n" << endl;
		cin >> ophthalmology;

		emp = new Veterinarian(name, age, sex, exp, anesthesiology, surgery, ophthalmology);
		break;
	}
	clearScreen();
	org.addEmployee(emp);
	cout << "Сотрудник добавлен!\n";
	pause();
}
void start::removeEmpMenu()
{
	while (1) {
		clearScreen();
		cout << "Выберите ID работника для увольнения:" << endl;
		showShortOrgInfo();
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "Неверный ID!\n";
			pause();
			continue;
		}
		cout << "Работник уволен!\n";
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
	cout << "Введите название зоопарка\n";
	string name;
	cin >> name;
	z.setZooName(name);
}
void start::setCityNameMenu()
{
	clearScreen();
	cout << "Введите название города\n";
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
		cout << "0- Вернуться назад";
		cout << "\nВыбрать ID животного: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Animal *anim = z.getAnimalById(ch);

		if (anim == nullptr)
		{
			cout << "Неверный ID\n";
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
		if (ani == "Bear") ani = "Медведь"; else if (ani == "Cat") ani = "Кошка";
		else if (ani == "Elephant") ani = "Слон"; else if (ani == "Giraffe") ani = "Жираф";
		else if (ani == "Kangaroo") ani = "Кенгуру"; else if (ani == "Monkey") ani = "Обезьяна";

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
		cout << "1. Изменить информацию о животном\n";
		cout << "2. Животное переезжает\n";
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
			cout << "Животное переехало!" << endl;
			pause();
			return;
			break;
		default:
			cout << "Неизвестная команда";
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
		cout << "\nВыберите какую информацию изменить\n";
		cout << ++index << ". Имя\n";
		cout << ++index << ". Цвет\n";
		cout << ++index << ". Возраст\n";

		int pos;
		if (typeid(*animal) == typeid(Bear))
		{
			pos = 1;
			cout << ++index << ". Вид медведя\n";
		}
		else if (typeid(*animal) == typeid(Cat))
		{
			pos = 2;
			cout << ++index << ". Порода \n";


		}
		else if (typeid(*animal) == typeid(Elephant))
		{
			pos = 3;
			cout << ++index << ". Длина хобота (см) \n";
			cout << ++index << ". Есть ли бивни? (1 - да, 0 - нет) \n";

		}
		else if (typeid(*animal) == typeid(Giraffe))
		{
			pos = 4;
			cout << ++index << ". Длина шеи \n";
		}
		else if (typeid(*animal) == typeid(Kangaroo))
		{
			pos = 5;
			cout << ++index << ". Размер сумки \n";
		}
		else if (typeid(*animal) == typeid(Monkey))
		{
			pos = 6;
			cout << ++index << ". Вид обезьяны \n";
		}

		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Неизвестная команда!\n";
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
			cout << "\n Введите новое имя: ";
			cin >> name;
			animal->setName(name);
			break;
		}
		case 2:
		{
			string color;
			cout << "\n Введите новый возраст: ";
			cin >> color;
			animal->setColor(color);
			break;
		}
		case 3:
		{
			int age;
			cout << "\n Введите новый возраст: ";
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
					cout << "Введите вид медведя\n";
					string type;
					cin >> type;
					((Bear*)animal)->setType(type);
				}
				break;
			case 2:
				if (ch == 4)
				{
					cout << "Введите породу\n";
					string breed;
					cin >> breed;
					((Cat*)animal)->setBreed(breed);
				}
				break;
			case 3:
				if (ch == 4)
				{
					cout << "Введите длину хобота\n";
					int trunkLength;
					cin >> trunkLength;
					((Elephant*)animal)->setTrunkLength(trunkLength);
				}
				else
				{
					cout << "Есть ли бивни\n";
					bool hasTusk;
					cin >> hasTusk;
					((Elephant*)animal)->setHasTusk(hasTusk);
				}
				break;
			case 4:
				if (ch == 4)
				{
					cout << "Размер шеи\n";
					int neckLength;
					cin >> neckLength;
					((Giraffe*)animal)->setNeckLength(neckLength);
				}
				break;
			case 5:
				if (ch == 4)
				{
					cout << "Размер сумки\n";
					int bagSize;
					cin >> bagSize;
					((Kangaroo*)animal)->setBagSize(bagSize);
				}
				break;
			case 6:
				if (ch == 4)
				{
					cout << "Вид обезьяны\n";
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
	cout << "Введите имя организации: \n";
	string name;
	cin >> name;
	org.setName(name);
}
void start::setSalaryMenu()
{
	clearScreen();
	cout << "Введите зарплату: \n";
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
		cout << "0- Вернуться назад";
		cout << "\nВыберите ID работника: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "Неверный ID!\n";
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
		if (emp == "Director") emp = "Директор";
		else if (emp == "Gardener") emp = "Садовник";
		else if (emp == "Keeper") emp = "Смотритель";
		else if (emp == "Manager") emp = "Менеджер";
		else if (emp == "Veterinarian") emp = "Ветеринар";

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
		cout << "1. Изменить информацию о сотруднике\n";
		cout << "2. Уволить сотрудника\n";
		cout << "3. Поменять позицию сотрудника\n";
		cout << "0. Назад\n";
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
			cout << "Работник уволен!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
		default:
			cout << "Неизвестная команда";
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
		cout << "\nВыберите информацию для изменения: \n";
		cout << ++index << ". Имя\n";
		cout << ++index << ". Возраст\n";
		cout << ++index << ". Пол\n";
		cout << ++index << ". Опыт работы\n";
		int pos;
		if (typeid(*emp) == typeid(Gardener))
		{
			pos = 1;
			cout << ++index << ". Творческие навыки\n";
		}
		else if (typeid(*emp) == typeid(Keeper))
		{
			pos = 2;
			cout << ++index << ". Внимательность\n";
		}
		else if (typeid(*emp) == typeid(Manager))
		{
			pos = 3;
			cout << ++index << ". Коммуникативные навыки\n";
			cout << ++index << ". Высшее образование\n";

		}
		else if (typeid(*emp) == typeid(Veterinarian))
		{
			pos = 4;
			cout << ++index << ". Навыки\n";			
		}
		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Неизвестная комманда!\n";
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
			cout << "\nВведите новое имя: ";
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			int age;
			cout << "\nВведите возрас: ";
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			string sex;
			cout << "\nВведите пол: ";
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			int exp;
			cout << "\nВведите опыт работы: ";
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
					cout << "Введите имеются ли творческие навыки\n";
					bool creativeSkills;
					cin >> creativeSkills;
					((Gardener*)emp)->setCreativeSkills(creativeSkills);
				}
				break;
			case 2:
				if (ch == 5)
				{
					cout << "Внимательный сотрудник?\n";
					bool attentiveness;
					cin >> attentiveness;
					((Keeper*)emp)->setAttentiveness(attentiveness);
				}
				break;
			case 3:
				if (ch == 5)
				{
					cout << "Имеются ли коммуникативные навыки\n";
					bool commSkills;
					cin >> commSkills;
					((Manager*)emp)->setCommunicationSkills(commSkills);
				}
				else
				{
					cout << "Есть ли высшее образование\n";
					bool hasEdu;
					cin >> hasEdu;
					((Manager*)emp)->setHasEdu(hasEdu);
				}
				break;
			case 4:
				if (ch == 5)
				{
					cout << "Есть ли следующие навыки:\n";
					bool anastSkills;
					bool surgSkills;
					bool ophSkills;
					cout << "Анастезии: ";
					cin >> anastSkills;
					cout << "Хирургии: ";
					cin >> surgSkills;
					cout << "Офтальмологии: ";
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
		cout << "Выберите новую позицию для работника " << emp->getPosition() << " " << emp->getName() << endl;
		cout << "1. Директор\n";
		cout << "2. Садовник\n";
		cout << "3. Смотритель\n";
		cout << "4. Менеджер\n";
		cout << "5. Ветеринар\n";
		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "Неизвестная команда\n";
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