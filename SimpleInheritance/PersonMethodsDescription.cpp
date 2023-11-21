#include "Header.h"

void Person::InputData() {
	cout << "������� ���: ";
	getline(cin, FullName);
	cout << "������� ��� ��������: ";
	cin >> YearOfBirth;
	while (YearOfBirth < 0 || YearOfBirth > 2023 || !cin || (getchar() != '\n')) {
		if (YearOfBirth < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else if (YearOfBirth > 2023) {
			cout << "�� ����� ����� 2023 ���!" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> YearOfBirth;
	}
	cout << "������� ����� ��������: ";
	cin >> PassportSeries;
	cout << "������� ����� ��������: ";
	cin >> PassportNumber;
	while (PassportNumber < 0 || !cin || (getchar() != '\n')) {
		if (PassportNumber < 0) {
			cout << "����� �� ����� ���� �������������! ��������� ����:" << endl;
		}
		else {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
		}
		cin.clear();
		rewind(stdin);
		cin >> PassportNumber;
	}
}

void Person::OutputData() {
	cout << "���: " << FullName << endl;
	cout << "��� ��������: " << YearOfBirth << endl;
	cout << "����� � ����� ��������: " << PassportSeries << PassportNumber << endl;
}

ofstream Person::WriteInFile(string path) {
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << endl << FullName << endl << YearOfBirth << endl << PassportSeries << PassportNumber;
	}
	return file;
}

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}

int Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person* arr[10];
	arr[0] = new Person("������ ���� ��������", 1998, "AB", 1237843);
	arr[1] = new Person("������ ���� ��������", 1993, "AB", 7843231);
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
		cout << "1. ��������� ������" << endl << "2. ������� ������" << endl
			<< "3. �������� ������� �������" << endl << "4. ����� ������ �������� ��������\n"
			<< "0. ����� �� ���������" << endl << endl << "��� ������� �������? (1, 2, 3, 4, 0)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			system("cls");
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> n;
		}
		switch (n) {
		case 1:
			system("cls");
			for (int i = 2; i < 10; i++) {
				/*if (i < 2) {
					cout << "������� ������ � ��������" << endl;
					arr[i]->InputData();
					ofstream file = arr[i]->WriteInFile("Person.txt");
					file.close();
				}*/
				if (i < 4) {
					cout << "������� ������ � ���������������" << endl;
					arr[i]->InputData();
				}
				else if (i < 6) {
					cout << "������� ������ � �������" << endl;
					arr[i]->InputData();
				}
				else if (i < 8) {
					cout << "������� ������ � �������" << endl;
					arr[i]->InputData();
				}
				else {
					cout << "������� ������ � ����������" << endl;
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
			cout << "������� ����� �������, ������� ������ ��������. (1-10)" << endl;
			cin >> k;
			while (k < 1 || k > 10 || !cin || (getchar() != '\n')) {
				if (k < 1 || k > 10) {
					cout << "������� � ����� ������� �� ����������! ��������� ����:" << endl;
				}
				else {
					cout << "����� ������ ����� �����! ��������� ����:" << endl;
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
			cout << "������ ������ �������� ��������:\n" << endl;
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


//������ �1. ����������� ������������� ��������� ������� � ��������� ������ ��� ������������
class BankAccount { // ������� �����
protected:
	float balance;
public:
	string owner;
	void deposit();
};
class SavingAccount :BankAccount {// ����������� �����
	float annualInterestRate;
public:
	void showData() {
		balance = 1000.5;//������, balance �������� private ���������� ������ BankAccount � �������� ������ ��� ������� � 
						 //������������� ������� ����� ������
		annualInterestRate = 0.5;//������ � ���������� ���� private �� ������ �������� ������
		owner = "N/A";//���� owner ������������ �� ������ BankAccount � ��������� ������� private, �������� � ������ �������� ������
	}
};
void Ex1() {
	BankAccount bankAccount;//�������� ������� ������ BankAccount
	SavingAccount savingAccount;//�������� ������� ������ SavingAccount
	//savingAccount.owner = "Ivanov"; //������, �.�. owner ����� ������� ������� private (member is inaccessible)
	bankAccount.owner = "Petrov"; // ���������� ��������
}

//������ �2. ������ ������������ �� ������ Counter
class Counter {//������� �����
protected:
	unsigned int count;//�������
public:
	Counter() :count(0) {}//����������� ��� ����������
	Counter(int c) :count(c) {}//����������� � ����� ����������
	//���������� �������� ��������
	unsigned int getCount() const { return count; }
	//���������� ���������� �������� ��������
	Counter operator++() { return Counter(++count); }
};
class CountDn :public Counter {//����������� �����
public:
	//��������� �������� ��������
	Counter operator--() { return Counter(--count); }
};
void Ex2() {
	CountDn c1;//������� ������ c1
	cout << "c1=" << c1.getCount();//����� �������� �������� �� ����� 
	++c1; ++c1; ++c1;//����������� �������� �������� � ������� c1 ��� ����
	cout << "\nc1=" << c1.getCount();//����� �������� �������� �� �����
	--c1; --c1;//��������� �������� �������� c1 ��� ����
	cout << "\nc1=" << c1.getCount();//����� �������� �������� �� �����
}

//������ �3. �������� ������ ������� � �������������� ������������ ��� �������� ������ �����������
class Employee {//��������� ��������
	string fullName;//��� ����������
	unsigned long ID;//����� ����������
public:
	Employee() {
		cout << "������� ���: ";
		getline(cin, fullName, '\n');
		cout << "������� ����� ����������: ";
		cin >> ID;
		cin.ignore(32767, '\n');
	}
	virtual void putData() const {
		cout << "\n���: " << fullName;
		cout << "\n�����: " << ID;
	}
};
class Manager :public Employee {//�������� ��������
	string position;//��������� ��������� (�� ��������, ��������)
	float dues;//����� ������� ��� ���������� ���������
public:
	Manager() {
		cout << "������� ��������� ���������: ";
		getline(cin, position, '\n');
		cout << "������� ����� ������� ��� ���������� ���������: ";
		cin >> dues;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Employee::putData();
		cout << "\n���������: " << position;
		cout << "\n����� ������� ��� ���������� ���������: " <<
			dues;
	}
};
class Scientist :public Employee {//������� ���������
	int numberOfPublications;//���������� ����������
public:
	Scientist() {
		cout << "������� ���������� ����������: ";
		cin >> numberOfPublications;
		cin.ignore(32767, '\n');
	}
	void putData() const {
		Employee::putData();
		cout << "\n���������� ����������: " << numberOfPublications;
	}
};
class Laborer :public Employee {};//�������
void Ex3() {
	Employee* emp[4];
	cout << "������� ������ � ������ ���������:" << endl;
	emp[0] = new Manager();
	cout << "\n������� ������ � ������ ���������" << endl;
	emp[1] = new Manager();
	cout << "\n������� ������ �� ������" << endl;
	emp[2] = new Scientist();
	cout << "\n������� ������ � �������" << endl;
	emp[3] = new Laborer();
	cout << "\n������ � ������ ���������";
	emp[0]->putData();
	cout << "\n������ � ������ ���������";
	emp[1]->putData();
	cout << "\n������ �� ������";
	emp[2]->putData();
	cout << "\n������ � �������";
	emp[3]->putData();
	return;
}