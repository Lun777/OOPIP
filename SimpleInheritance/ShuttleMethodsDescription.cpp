#include "Header.h"

void Shuttle::InputData() {
	Person::InputData();
	if (!p) {
		cout << "������� ���������� �������, �� ������� ��������� �����" << endl;
		cin >> size;
		while (size < 0 || !cin || (getchar() != '\n')) {
			if (size < 0) {
				cout << "������ �� ����� ���� �������������! ��������� ����:" << endl;
			}
			else {
				cout << "����� ������ ����� �����! ��������� ����:" << endl;
			}
			cin.clear();
			rewind(stdin);
			cin >> size;
		}
		p = new string[size];
	}
	cout << "������� ������, �� ������� ��������� �����:" << endl;
	for (int i = 0; i < size; i++) {
		getline(cin, p[i]);
	}
	ofstream file = WriteInFile("Shuttle.txt");
	file.close();
}

void Shuttle::OutputData() {
	Person::OutputData();
	if (!p) {
		cout << "����� ����� �� �������" << endl;
		return;
	}
	cout << "������ �� ������� ��������� �����: ";
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
		file << endl << "����� ����� �� �������";
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