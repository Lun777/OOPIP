#include "Header.h"

void Person::InputData() {
	cout << "Введите ФИО: ";
	getline(cin, FullName);
	cout << "Введите год рождения: ";
	cin >> YearOfBirth;
	while (YearOfBirth < 0 || YearOfBirth > 2023 || !cin || (getchar() != '\n')) {
		if (YearOfBirth < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else if (YearOfBirth > 2023) {
			cout << "На дворе стоит 2023 год!" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> YearOfBirth;
	}
	cout << "Введите серию паспорта: ";
	cin >> PassportSeries;
	cout << "Введите номер паспорта: ";
	cin >> PassportNumber;
	while (PassportNumber < 0 || !cin || (getchar() != '\n')) {
		if (PassportNumber < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> PassportNumber;
	}
}

void Person::OutputData() {
	cout << "ФИО: " << FullName << endl;
	cout << "Год рождения: " << YearOfBirth << endl;
	cout << "Серия и номер паспорта: " << PassportSeries << PassportNumber << endl;
}

ofstream Person::WriteInFile(string path) {
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
	}
	else {
		file << endl << endl << FullName << endl << YearOfBirth << endl << PassportSeries << PassportNumber;
	}
	return file;
}

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}

int Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person* arr[10];
	arr[0] = new Person("Иванов Иван Иванович", 1998, "AB", 1237843);
	arr[1] = new Person("Петров Петр Петрович", 1993, "AB", 7843231);
	arr[2] = new Employer();
	arr[3] = new Employer();
	arr[4] = new Tourist();
	arr[5] = new Tourist();
	arr[6] = new Shuttle();
	arr[7] = new Shuttle();
	arr[8] = new Footballer();
	arr[9] = new Footballer();
	int n;
	while (1) {
		cout << "1. Заполнить массив" << endl << "2. Вывести массив" << endl
			<< "3. Изменить элемент массива" << endl << "4. Найти самого старшего человека\n"
			<< "0. Выйти из программы" << endl << endl << "Что желаете выбрать? (1, 2, 3, 4, 0)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			system("cls");
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> n;
		}
		switch (n) {
		case 1:
			system("cls");
			for (int i = 2; i < 10; i++) {
				/*if (i < 2) {
					cout << "Введите данные о человеке" << endl;
					arr[i]->InputData();
					ofstream file = arr[i]->WriteInFile("Person.txt");
					file.close();
				}*/
				if (i < 4) {
					cout << "Введите данные о предпринимателе" << endl;
					arr[i]->InputData();
				}
				else if (i < 6) {
					cout << "Введите данные о туристе" << endl;
					arr[i]->InputData();
				}
				else if (i < 8) {
					cout << "Введите данные о челноке" << endl;
					arr[i]->InputData();
				}
				else {
					cout << "Введите данные о футболисте" << endl;
					arr[i]->InputData();
				}
				cout << endl;
			}
			DeleteConsole();
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 10; i++) {
				arr[i]->OutputData();
				cout << endl;
			}
			DeleteConsole();
			break;
		case 3:
			system("cls");
			int k;
			cout << "Введите номер объекта, который хотите изменить. (1-10)" << endl;
			cin >> k;
			while (k < 1 || k > 10 || !cin || (getchar() != '\n')) {
				if (k < 1 || k > 10) {
					cout << "Объекта с таким номером не существует! Повторите ввод:" << endl;
				}
				else {
					cout << "Нужно ввести целое число! Повторите ввод:" << endl;
				}
				cin.clear();
				rewind(stdin);
				cin >> k;
			}
			arr[k - 1]->InputData();
			cout << endl;
			DeleteConsole();
			break;
		case 4:
		{
			system("cls");
			int max = 2023 - arr[0]->GetYearOfBirth();
			int index = 0;
			for (int i = 1; i < 10; i++) {
				if (2023 - arr[i]->GetYearOfBirth() > max) {
					max = 2023 - arr[i]->GetYearOfBirth();
					index = i;
				}
			}
			cout << "Данные самого старшего человека:\n" << endl;
			arr[index]->OutputData();
			cout << endl;
			DeleteConsole();
		}
		break;
		case 0:
			return 0;
			break;
		}
	}
}


//Пример №1. Особенности использование атрибутов доступа к элементам класса при наследовании
class BankAccount { // базовый класс
protected:
	float balance;
public:
	string owner;
	void deposit();
};
class SavingAccount :BankAccount {// производный класс
	float annualInterestRate;
public:
	void showData() {
		balance = 1000.5;//ошибка, balance является private переменной класса BankAccount и доступна только для методов и 
						 //дружественных функций этого класса
		annualInterestRate = 0.5;//доступ к переменной типа private из метода текущего класса
		owner = "N/A";//поле owner унаследовано из класса BankAccount с атрибутом доступа private, доступно в методе текущего класса
	}
};
void Ex1() {
	BankAccount bankAccount;//создание объекта класса BankAccount
	SavingAccount savingAccount;//создание объекта класса SavingAccount
	//savingAccount.owner = "Ivanov"; //ошибка, т.к. owner имеет атрибут доступа private (member is inaccessible)
	bankAccount.owner = "Petrov"; // допустимая операция
}

//Пример №2. Пример наследования от класса Counter
class Counter {//базовый класс
protected:
	unsigned int count;//счетчик
public:
	Counter() :count(0) {}//конструктор без аргументов
	Counter(int c) :count(c) {}//конструктор с одним параметром
	//возвращает значение счетчика
	unsigned int getCount() const { return count; }
	//префиксное увеличение значения счетчика
	Counter operator++() { return Counter(++count); }
};
class CountDn :public Counter {//производный класс
public:
	//уменьшает значение счетчика
	Counter operator--() { return Counter(--count); }
};
void Ex2() {
	CountDn c1;//создаем объект c1
	cout << "c1=" << c1.getCount();//вывод значения счетчика на экран 
	++c1; ++c1; ++c1;//увеличиваем значение счетчика в объекте c1 три раза
	cout << "\nc1=" << c1.getCount();//вывод значения счетчика на экран
	--c1; --c1;//уменьшаем значения счетчика c1 два раза
	cout << "\nc1=" << c1.getCount();//вывод значения счетчика на экран
}

//Пример №3. Создание набора классов с использованием наследования для хранения данных сотрудников
class Employee {//сотрудник компании
	string fullName;//ФИО сотрудника
	unsigned long ID;//номер сотрудника
public:
	Employee() {
		cout << "Введите ФИО: ";
		getline(cin, fullName, '\n');
		cout << "Введите номер сотрудника: ";
		cin >> ID;
		cin.ignore(32767, '\n');
	}
	virtual void putData() const {
		cout << "\nФИО: " << fullName;
		cout << "\nНомер: " << ID;
	}
};
class Manager :public Employee {//менеджер компании
	string position;//должность менеджера (по продажам, закупкам)
	float dues;//сумма взносов для проведения тренингов
public:
	Manager() {
		cout << "Введите должность менеджера: ";
		getline(cin, position, '\n');
		cout << "Введите сумму взносов для проведения тренингов: ";
		cin >> dues;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Employee::putData();
		cout << "\nДолжность: " << position;
		cout << "\nСумма взносов для проведения тренингов: " <<
			dues;
	}
};
class Scientist :public Employee {//научный сотрудник
	int numberOfPublications;//количество публикаций
public:
	Scientist() {
		cout << "Введите количество публикаций: ";
		cin >> numberOfPublications;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Employee::putData();
		cout << "\nКоличество публикаций: " << numberOfPublications;
	}
};
class Laborer :public Employee {};//рабочий
void Ex3() {
	Employee* emp[4];
	cout << "Введите данные о первом менеджере:" << endl;
	emp[0] = new Manager();
	cout << "\nВведите данные о втором менеджере" << endl;
	emp[1] = new Manager();
	cout << "\nВведите данные об учёном" << endl;
	emp[2] = new Scientist();
	cout << "\nВведите данные о рабочем" << endl;
	emp[3] = new Laborer();
	cout << "\nДанные о первом менеджере";
	emp[0]->putData();
	cout << "\nДанные о втором менеджере";
	emp[1]->putData();
	cout << "\nДанные об учёном";
	emp[2]->putData();
	cout << "\nДанные о рабочем";
	emp[3]->putData();
	return;
}