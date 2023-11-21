#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

#define N 3

using namespace std;

void Ex1();
void Ex2();
void Ex3();

void DeleteConsole();

class Person {
	string FullName;
	int YearOfBirth;
	string PassportSeries;
	unsigned long int PassportNumber;
public:
	Person() {
		FullName = "Сидоров Алексей Иванович";
		YearOfBirth = 1999l;
		PassportSeries = "AB";
		PassportNumber = 6547890;
	};
	Person(string FullName, int YearOfBirth, string PassportSeries, unsigned long int PassportNumber) {
		this->FullName = FullName;
		this->YearOfBirth = YearOfBirth;
		this->PassportSeries = PassportSeries;
		this->PassportNumber = PassportNumber;
	}
	Person(const Person& human) {
		FullName = human.FullName;
		YearOfBirth = human.YearOfBirth;
		PassportSeries = human.PassportSeries;
		PassportNumber = human.PassportNumber;
	}
	virtual void InputData();
	virtual void OutputData();
	virtual ofstream WriteInFile(string path);
	int GetYearOfBirth() {
		return YearOfBirth;
	}
};

class Employer : public Person {
	unsigned long int LicenseNumber;
	string RegAddress;
	unsigned long int TIN;
	double PaymentAmount;
public:
	Employer() {
		LicenseNumber = 47382;
		RegAddress = "Ул. Пушкина, д.32";
		TIN = 23175;
		PaymentAmount = 1000;
	}
	void InputData();
	void OutputData();
	ofstream WriteInFile(string path);
};

class Tourist : public Person {
	string Country;
	string ArrivalDate;
	string CrossingPoint;
public:
	Tourist() {
		Country = "Республика Беларусь";
		ArrivalDate = "21.03.2023";
		CrossingPoint = "Brest";
	}
	void InputData();
	void OutputData();
	ofstream WriteInFile(string path);
};

class Shuttle : public Person {
	int size;
	string* p;
public:
	Shuttle() {
		size = 0;
		p = 0;
	}
	Shuttle(int size) {
		this->size = size;
		p = new string[size];
	}
	~Shuttle() {
		delete[] p;
	}
	Shuttle(const Shuttle& seller) {
		size = seller.size;
		p = new string[size];
		for (int i = 0; i < size; i++) {
			p[i] = seller.p[i];
		}
	}
	void InputData();
	void OutputData();
	ofstream WriteInFile(string path);
};

class Footballer : public Person {
	int number;
	string team;
	double salary;
public:
	Footballer() {
		number = 43;
		team = "Динамо-Минск";
		salary = 10000;
	}
	void InputData();
	void OutputData();
	ofstream WriteInFile(string path);
};

int Program();