#include "Header.h"

void Footballer::InputData() {
	Person::InputData();
	cout << "Введите номер, под которым играете: ";
	cin >> number;
	while (number < 0 || !cin || (getchar() != '\n')) {
		if (number < 0) {
			cout << "Номер не может быть отрицательным! Повторите ввод:" << endl;
		}
		else {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> number;
	}
	cout << "Введите команду, в которой играете: ";
	getline(cin, team);
	cout << "Введите вашу заработную плату: ";
	cin >> salary;
	cin.get();
	ofstream file = WriteInFile("Footballer.txt");
	file.close();
}

void Footballer::OutputData() {
	Person::OutputData();
	cout << "Игровой номер: " << number << endl;
	cout << "Команда: " << team << endl;
	cout << "Зарплата: " << salary << endl;
}

ofstream Footballer::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << number << endl << team << endl << salary;
	return file;
}