#include "Header.h"

void Tourist::InputData() {
	Person::InputData();
	cout << "Введите страну, которую посещали: ";
	getline(cin, Country);
	cout << "Введите дату пересечения границы: ";
	getline(cin, ArrivalDate);
	cout << "Введите пункт пропуска: ";
	getline(cin, CrossingPoint);
	ofstream file = WriteInFile("Tourist.txt");
	file.close();
}

void Tourist::OutputData() {
	Person::OutputData();
	cout << "Страна: " << Country << endl;
	cout << "Дата пересечения границы: " << ArrivalDate << endl;
	cout << "Пункт пропуска: " << CrossingPoint << endl;
}

ofstream Tourist::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << Country << endl << ArrivalDate << endl << CrossingPoint;
	return file;
}