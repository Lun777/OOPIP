#include "Header.h"

void Footballer::InputData() {
	Person::InputData();
	cout << "������� �����, ��� ������� �������: ";
	cin >> number;
	while (number < 0 || !cin || (getchar() != '\n')) {
		if (number < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> number;
	}
	cout << "������� �������, � ������� �������: ";
	getline(cin, team);
	cout << "������� ���� ���������� �����: ";
	cin >> salary;
	cin.get();
	ofstream file = WriteInFile("Footballer.txt");
	file.close();
}

void Footballer::OutputData() {
	Person::OutputData();
	cout << "������� �����: " << number << endl;
	cout << "�������: " << team << endl;
	cout << "��������: " << salary << endl;
}

ofstream Footballer::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << number << endl << team << endl << salary;
	return file;
}