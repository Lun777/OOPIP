#include "Header.h"

void Employer::InputData() {
	Person::InputData();
	cout << "Введите номер лицензии: ";
	cin >> LicenseNumber;
	while (LicenseNumber < 0 || !cin || (getchar() != '\n')) {
		if (LicenseNumber < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> LicenseNumber;
	}
	cout << "Введите регистрационный адрес: ";
	getline(cin, RegAddress);
	cout << "Введите учётный номер налогоплательщика: ";
	cin >> TIN;
	while (TIN < 0 || !cin || (getchar() != '\n')) {
		if (TIN < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> TIN;
	}
	cout << "Введите общую сумму платежа: ";
	cin >> PaymentAmount;
	while (PaymentAmount < 0 || !cin || (getchar() != '\n')) {
		if (PaymentAmount < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> PaymentAmount;
	}
	ofstream file = WriteInFile("Employer.txt");
	file.close();
}

void Employer::OutputData() {
	Person::OutputData();
	cout << "Номер лицензии: " << LicenseNumber << endl;
	cout << "Регистрационный адрес: " << RegAddress << endl;
	cout << "Учётный номер налогоплательщика: " << TIN << endl;
	cout << "Общая сумма платежа: " << PaymentAmount << endl;
}

ofstream Employer::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << LicenseNumber << endl << RegAddress << endl << TIN << endl << PaymentAmount;
	return file;
}