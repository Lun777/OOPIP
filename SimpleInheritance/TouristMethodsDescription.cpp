#include "Header.h"

void Tourist::InputData() {
	Person::InputData();
	cout << "������� ������, ������� ��������: ";
	getline(cin, Country);
	cout << "������� ���� ����������� �������: ";
	getline(cin, ArrivalDate);
	cout << "������� ����� ��������: ";
	getline(cin, CrossingPoint);
	ofstream file = WriteInFile("Tourist.txt");
	file.close();
}

void Tourist::OutputData() {
	Person::OutputData();
	cout << "������: " << Country << endl;
	cout << "���� ����������� �������: " << ArrivalDate << endl;
	cout << "����� ��������: " << CrossingPoint << endl;
}

ofstream Tourist::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << Country << endl << ArrivalDate << endl << CrossingPoint;
	return file;
}