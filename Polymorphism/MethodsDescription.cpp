#include "Header.h"

void Input(int& var) {
	while (var < 0 || !cin || (getchar() != '\n')) {
		if (var < 0) {
			cout << "Отрицательное значение недопустимо! Повторите ввод:" << endl;

		}
		else {
			cout << "\nНекорректный ввод данных! Необходимо ввести целое число! Повторите ввод:" << endl;		//Проверяем на ввод целого числа
		}
		cin.clear();
		rewind(stdin);
		cin >> var;																					//Повторяем ввод если считано не целочисленное значение
	}
}

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}



void Transport::printInfo() {
	cout << "Расход топлива энергии: " << EnergyConsumption << " кВт*ч" << endl;
	cout << "Мощность двигателя: " << Power << " кВт" << endl;
	cout << "ФИО водителя: " << WorkerFullName << endl;
	cout << "Стаж водителя: " << WorkExp << " лет" << endl;
	cout << "Количество пассажирных мест: " << PassSeats << endl;
	cout << "Время эксплуатации: " << Lifetime << " лет" << endl;
	cout << "Пробег: " << Mileage << " км" << endl;
	cout << "Модель: " << Model << endl;
}

void Transport::changeData() {
	cout << "Введите расход топлива(энергии) (в кВт*ч): ";
	cin >> EnergyConsumption;
	Input(EnergyConsumption);
	cout << "Введите мощность двигателя (в кВт): ";
	cin >> Power;
	Input(Power);
	cout << "Введите ФИО водителя: ";
	getline(cin, WorkerFullName);
	cout << "Введите стаж водителя (в годах): ";
	cin >> WorkExp;
	Input(WorkExp);
	cout << "Введите количество пассажирских мест: ";
	cin >> PassSeats;
	Input(PassSeats);
	cout << "Введите кол-во лет эксплуатации транспорта (в годах): ";
	cin >> Lifetime;
	Input(Lifetime);
	cout << "Введите пробег машины (в км): ";
	cin >> Mileage;
	Input(Mileage);
	cout << "Введите модель машины: ";
	getline(cin, Model);
}

void Transport::WriteInFile(string Name, string path) {
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << endl << Name << endl << EnergyConsumption << " кВт*ч" << endl << Power << " кВт" << endl << WorkerFullName << endl << WorkExp << " лет"
			<< endl << PassSeats << endl << Lifetime << " лет" << endl << Mileage << " км" << endl << Model;
	}
	file.close();
}

void PublicTransport::printInfo() {
	Transport::printInfo();
	cout << "Юр. лицо: " << Entity << endl;
}

void PublicTransport::changeData() {
	Transport::changeData();
	cout << "Введите Юр. лицо владеющим транспортом: ";
	getline(cin, Entity);
}

void PublicTransport::WriteInFile(string Name, string path) {
	Transport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << Entity;
	}
	file.close();
}

void ElecTransport::printInfo() {
	PublicTransport::printInfo();
	cout << "Тип токоприёмников: " << Pantograph << endl;
}

void ElecTransport::changeData() {
	PublicTransport::changeData();
	cout << "Введите тип токоприёмников (штанговый или дуговой): ";
	getline(cin, Pantograph);
}

void ElecTransport::WriteInFile(string Name, string path) {
	PublicTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << Pantograph;
	}
	file.close();
}

void Tram::printInfo() {
	ElecTransport::printInfo();
	cout << "Тип трамвая: " << Type << endl;
}

void Tram::changeData() {
	ElecTransport::changeData();
	cout << "Введите тип трамвая: ";
	getline(cin, Type);
}

void Tram::WriteInFile(string Name, string path) {
	ElecTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << Type;
	}
	file.close();
}

void Minibus::printInfo() {
	PublicTransport::printInfo();
	cout << "Тип маршрута: " << RouteType << endl;
}

void Minibus::changeData() {
	PublicTransport::changeData();
	cout << "Введите тип маршрута (межгородской или внутригородской): ";
	getline(cin, RouteType);
}

void Minibus::WriteInFile(string Name, string path) {
	PublicTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << RouteType;
	}
	file.close();
}

void Car::printInfo() {
	Transport::printInfo();
	cout << "Физ. лицо: " << Individual << endl;
}

void Car::changeData() {
	Transport::changeData();
	cout << "Введите Физ. лицо владеющее машиной: ";
	getline(cin, Individual);
}

void Car::WriteInFile(string Name, string path) {
	Transport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << Individual;
	}
	file.close();
}

void Truck::printInfo() {
	Car::printInfo();
	cout << "Грузоподъёмность: " << CarryingCapacity << " т" << endl;
}

void Truck::changeData() {
	Car::changeData();
	cout << "Введите грузоподъёмность грузового автомобиля (в тоннах): ";
	cin >> CarryingCapacity;
	Input(CarryingCapacity);
}

void Truck::WriteInFile(string Name, string path) {
	Car::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << CarryingCapacity << " т";
	}
	file.close();
}

void Dumper::printInfo() {
	Truck::printInfo();
	cout << "Материалы, которые может перевозить самосвал: ";
	for (int i = 0; i < size; i++) {
		cout << p[i];
		if (i != size - 1) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

void Dumper::changeData() {
	Truck::changeData();
	cout << "Введите количество вариаций материалов, которые может перевозить самосвал: ";
	cin >> size;
	Input(size);
	p = new string[size];
	cout << "Введите материалы: " << endl;
	for (int i = 0; i < size; i++) {
		getline(cin, p[i]);
	}
}

void Dumper::WriteInFile(string Name, string path) {
	Truck::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl;
		for (int i = 0; i < size; i++) {
			file << p[i];
			if (i != size - 1) {
				file << ", ";
			}
		}
	}
	file.close();
}

void PassengerCar::printInfo() {
	Car::printInfo();
	cout << "Максимально развиваемая скорость: " << MaxSpeed << " км/ч" << endl;
}

void PassengerCar::changeData() {
	Car::changeData();
	cout << "Введите максимально развиваемую скорость легковой машиной (в км/ч): ";
	cin >> MaxSpeed;
	Input(MaxSpeed);
}

void PassengerCar::WriteInFile(string Name, string path) {
	Car::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << MaxSpeed << " км/ч";
	}
	file.close();
}



int Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Transport* arr[7];														// 1. Создание указателя на базовый класс
	arr[0] = new Bus();														// 2. Присвоение указателю на базовый класс адрес объекта дочернего класса
	arr[1] = new Trolleybus();												// и здесь
	arr[2] = new Tram();													// и здесь
	arr[3] = new Minibus();													// и здесь
	arr[4] = new Lorry();													// и здесь
	arr[5] = new Dumper();													// и здесь
	arr[6] = new PassengerCar();											// и здесь
	int n;
	while (1) {
		cout << "1. Заполнить массив" << endl << "2. Вывести массив" << endl
			<< "3. Изменить элемент массива" << endl << "0. Выйти из программы"
			<< endl << endl << "Что желаете выбрать? (1, 2, 3, 0)\n";
		cin >> n;
		Input(n);
		switch (n) {
		case 1:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << arr[i]->getName() << endl;							// 3. Вызов виртуального метода определённого в базовом классе и переопределённого в дочерних классах
				arr[i]->changeData();										// Вызов виртуального метода определяется типом адресуемого объекта
				cout << endl;
			}
			DeleteConsole();
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << i + 1 << ". ";
				cout << arr[i]->getName() << endl;
				arr[i]->printInfo();
				if (i != 6) {
					cout << "-------------------------------------------------------------------------------------------------------" << endl;
				}
				else {
					cout << endl;
				}
			}
			DeleteConsole();
			break;
		case 3:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << i + 1 << ". ";
				cout << arr[i]->getName() << endl;
				arr[i]->printInfo();
				if (i != 6) {
					cout << "-------------------------------------------------------------------------------------------------------" << endl;
				}
				else {
					cout << endl;
				}
			}
			int k;
			cout << "Введите номер объекта, который хотите изменить. (1-7)" << endl;
			cin >> k;
			while (k < 1 || k > 7 || !cin || (getchar() != '\n')) {
				if (k < 1 || k > 7) {
					cout << "Объекта с таким номером не существует! Повторите ввод:" << endl;
				}
				else {
					cout << "Нужно ввести целое число! Повторите ввод:" << endl;
				}
				cin.clear();
				rewind(stdin);
				cin >> k;
			}
			cout << endl;
			cout << arr[k - 1]->getName() << endl;
			arr[k - 1]->changeData();
			cout << endl;
			DeleteConsole();
			break;
		case 0:
			for (int i = 0; i < 7; i++) {
				string Name;
				Name = arr[i]->getName();
				arr[i]->WriteInFile(Name, "Transport.txt");

			}
			return 0;
			break;
		default:
			if (n > 3) {
				cout << "Такого номера не существует! Повторите ввод:" << endl;
				DeleteConsole();
			}
		}
	}
}



//Пример №1. Использование указателей на базовый класс для доступа к объектам производных классов
class BankAccount { // базовый класс 
protected:
	float balance;
public:
	BankAccount() { balance = 0; }
	string owner;
	void depositMoney(float sum) { balance += sum; }
	void showBalance() { cout << "balance=" << balance << endl; }
};
class SavingAccount :public BankAccount {// производный класс
	float annualInterestRate;
public:
	void withdrawMoney(int sum) {
		//balance = 1000.5;//ошибка, balance – private-переменная класса BankAccount и доступна только для методов и дружественных функций собственного класса
			annualInterestRate = 0.5;//доступ к переменной типа privateиз метода класса
			owner = "N/A";//owner унаследована из класса BankAccount с атрибутом доступа private и поэтому доступна в методе класса
			balance -= sum;
	}
};
void Ex1() {
	BankAccount* ptrBankAccount, bankAccount;
	SavingAccount* ptrSavingAccount, savingAccount;
	ptrBankAccount = &bankAccount; // адрес объекта базового класса
	ptrBankAccount->depositMoney(100);// Доступ к объекту через указатель
		ptrBankAccount = &savingAccount;
	ptrBankAccount->depositMoney(200);//Доступ к объекту через "базовый" указатель
		bankAccount.showBalance();
	savingAccount.showBalance();
	cout << "\n";
	//Поскольку метод withdrawMoney() не является частью базового класса, то он недоступен через "базовый" указатель, и к нему
	//необходимо обращаться либо непосредственно, либо через указатель на производный тип
	ptrSavingAccount = &savingAccount;
	ptrSavingAccount->withdrawMoney(50);
	ptrSavingAccount->showBalance();
}

//Пример №2. Использование виртуальной функции
class Shape { // базовый класс
public:
	virtual string getName(void) { return "no name"; }
	virtual float getArea(void) { return 0; }
};
class Rect : public Shape { // производный класс «Прямоугольник»
	float height, width; // размеры прямоугольника
public:
	Rect(float height, float width) {
		this->height = height;
		this -> width = width;
	}
	string getName(void) { return "прямоугольник"; }
	float getArea(void) { return height * width; }
};
class Circle : public Shape { // производный класс «Окружность»
	float radius; // радиус окружности
public:
	Circle(float radius) { this->radius = radius; }
	string getName(void) { return "круг"; }
	float getArea(void) { return 3.14f * radius * radius; }
};
void Ex2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Shape* ptrShapes[2]; // массив указателей на базовый класс
	Rect rect(3, 4);
	Circle circle(5);
	ptrShapes[0] = &rect;
	ptrShapes[1] = &circle;
	for (int i = 0; i < 2; i++)
		cout << "площадь " << ptrShapes[i]->getName() << setw(8) << ptrShapes[i]->getArea() << endl;
}

//Пример №3. Использование виртуальной функции
class Student { // базовый класс
protected:
	string specialization; // название специальности
	int group; // номер группы
public:
	Student(string specialization, int group) { // конструктор
		this->specialization = specialization;
		this->group = group;
	}
	~Student() { // деструктор
		cout << "деструктор класса Student" << endl;
	}
	virtual void print(void); // объявление виртуальной функции
};
class GraduateStudent : public Student { // производный класс
	string fullName; // ФИО
	int marks[4]; // массив оценок
public:
	GraduateStudent(string specialization, long group, string
		fullName, int marks[]) :Student(specialization, group) {
		this->fullName = fullName;
		for (int i = 0; i < 4; i++) this->marks[i] = marks[i];
	}
	~GraduateStudent() {
		cout << "Деструктор класса GraduateStudent" << endl;
	}
	void print(void);
};
void Student::print(void) { // реализация виртуальной функции
	cout << setw(10) << "Специальность" << setw(10) << "Группа" <<
		endl;
	cout << setw(10) << specialization << setw(10) << group << endl;
}
void GraduateStudent::print(void) {
	Student::print(); // вызов функции базового класса
	cout << setw(10) << "ФИО" << setw(fullName.length() + 3) << " Оценки" << endl;
		cout << setw(10) << fullName;
	for (int i = 0; i < 4; i++) cout << setw(4) << marks[i];
	cout << endl;
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int marks[] = { 4,5,5,4 }; // массив оценок
	string specialization;
	long group;
	string fullName;
	cout << "Введите название специальности" << endl;
	getline(cin, specialization, '\n');
	cout << "Введите номер группы" << endl;
	cin >> group;
	cin.ignore(10, '\n');
	cout << "Введите ФИО" << endl;
	getline(cin, fullName, '\n');
	Student student(specialization, group), * ptrStudent;
	GraduateStudent graduateStudent(specialization, group, fullName,
		marks);
	cout << "Данные:" << endl;
	//ptrStudent =&student; // указатель типа базового класса может хранить адрес объекта базового класса
		//ptrStudent->print(); // вызов функции базового класса
		ptrStudent = &graduateStudent;// указатель типа базового класса хранит адрес объекта производного класса
		ptrStudent->print(); // вызов функции производного класса
}