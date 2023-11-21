#include "Header.h"

void Shuttle::InputData() {
	Person::InputData();
	if (!p) {
		cout << "Введите количество адресов, по которым покупался товар" << endl;
		cin >> size;
		while (size < 0 || !cin || (getchar() != '\n')) {
			if (size < 0) {
				cout << "Размер не может быть отрицательным! Повторите ввод:" << endl;
			}
			else {
				cout << "Нужно ввести целое число! Повторите ввод:" << endl;
			}
			cin.clear();
			rewind(stdin);
			cin >> size;
		}
		p = new string[size];
	}
	cout << "Введите адреса, по которым покупался товар:" << endl;
	for (int i = 0; i < size; i++) {
		getline(cin, p[i]);
	}
	ofstream file = WriteInFile("Shuttle.txt");
	file.close();
}

void Shuttle::OutputData() {
	Person::OutputData();
	if (!p) {
		cout << "Товар никто не покупал" << endl;
		return;
	}
	cout << "Адреса по которым покупался товар: ";
	for (int i = 0; i < size; i++) {
		cout << p[i];
		if (i != size - 1) {
			cout << ";   ";
		}
	}
	cout << endl;
}

ofstream Shuttle::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	if (!p) {
		file << endl << "Товар никто не покупал";
		return file;
	}
	else {
		file << endl;
		for (int i = 0; i < size; i++) {
			file << p[i];
			if (i != size - 1) {
				file << ";   ";
			}
		}
		return file;
	}
}