#include "Header.h"

void Employer::InputData() {
	Person::InputData();
	cout << "������� ����� ��������: ";
	cin >> LicenseNumber;
	while (LicenseNumber < 0 || !cin || (getchar() != '\n')) {
		if (LicenseNumber < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> LicenseNumber;
	}
	cout << "������� ��������������� �����: ";
	getline(cin, RegAddress);
	cout << "������� ������� ����� �����������������: ";
	cin >> TIN;
	while (TIN < 0 || !cin || (getchar() != '\n')) {
		if (TIN < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> TIN;
	}
	cout << "������� ����� ����� �������: ";
	cin >> PaymentAmount;
	while (PaymentAmount < 0 || !cin || (getchar() != '\n')) {
		if (PaymentAmount < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
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
	cout << "����� ��������: " << LicenseNumber << endl;
	cout << "��������������� �����: " << RegAddress << endl;
	cout << "������� ����� �����������������: " << TIN << endl;
	cout << "����� ����� �������: " << PaymentAmount << endl;
}

ofstream Employer::WriteInFile(string path) {
	ofstream file = Person::WriteInFile(path);
	file << endl << LicenseNumber << endl << RegAddress << endl << TIN << endl << PaymentAmount;
	return file;
}