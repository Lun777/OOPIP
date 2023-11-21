#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

void Input(int& var);

void DeleteConsole();

class Transport {
	int EnergyConsumption;
	int Power;
	string WorkerFullName;
	int WorkExp;
	int PassSeats;
	int Lifetime;
	int Mileage;
	string Model;
public:
	Transport(string Name, int EnergyConsumption, int Power, string WorkerFullName, int WorkExp, int PassSeats, int Lifetime, int Mileage, string Model) {
		this->EnergyConsumption = EnergyConsumption;
		this->Power = Power;
		this->WorkerFullName = WorkerFullName;
		this->WorkExp = WorkExp;
		this->PassSeats = PassSeats;
		this->Lifetime = Lifetime;
		this->Mileage = Mileage;
		this->Model = Model;
	}
	Transport() {
		EnergyConsumption = 100;
		Power = 20;
		WorkerFullName = "Иванов Иван Иванович";
		WorkExp = 8;
		PassSeats = 15;
		Lifetime = 4;
		Mileage = 0;
		Model = "Lamborgini";
	}
	virtual string getName() = 0;
	virtual void printInfo();
	virtual void changeData();
	virtual void WriteInFile(string Name, string path);
};

// entity, individual

class PublicTransport : public Transport {
	string Entity;
public:
	PublicTransport(string Entity) {
		this->Entity = Entity;
	}
	PublicTransport() {
		Entity = "BelAvto";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Bus : public PublicTransport {
	string getName() {
		return "Автобус";
	}
};

class ElecTransport : public PublicTransport {
	string Pantograph;
public:
	ElecTransport(string Pantograph) {
		this->Pantograph = Pantograph;
	}
	ElecTransport() {
		Pantograph = "Штанговый";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Tram : public ElecTransport {
	string Type;
public:
	Tram(string Type) {
		this->Type = Type;
	}
	Tram() {
		Type = "Городской";
	}
	string getName() {
		return "Трамвай";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Trolleybus : public ElecTransport {
public:
	string getName() {
		return "Троллейбус";
	}
};

class Minibus : public PublicTransport {
	string RouteType;
public:
	Minibus(string RouteType) {
		this->RouteType = RouteType;
	}
	Minibus() {
		RouteType = "Межгородской";
	}
	string getName() {
		return "Маршрутное такси";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Car : public Transport {
	string Individual;
public:
	Car(string Individual) {
		this->Individual = Individual;
	}
	Car() {
		Individual = "Винни Пух";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Truck : public Car {
	int CarryingCapacity;
public:
	Truck(int CarryingCapacity) {
		this->CarryingCapacity = CarryingCapacity;
	}
	Truck() {
		CarryingCapacity = 500;
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class Lorry : public Truck {
public:
	string getName() {
		return "Грузовик";
	}
};

class Dumper : public Truck {
	string* p;
	int size;
public:
	Dumper(int size) {
		this->size = size;
		p = new string[size];
	}
	Dumper() {
		size = 3;
		p = new string[size];
		p[0] = "Песок";
		p[1] = "Гравий";
		p[2] = "Щебень";
	}
	~Dumper() {
		delete[] p;
	}
	Dumper(const Dumper& other) {
		size = other.size;
		p = new string[size];
		for (int i = 0; i < size; i++) {
			p[i] = other.p[i];
		}
	}
	string getName() {
		return "Самосвал";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

class PassengerCar : public Car {
	int MaxSpeed;
public:
	PassengerCar(int MaxSpeed) {
		this->MaxSpeed = MaxSpeed;
	}
	PassengerCar() {
		MaxSpeed = 300;
	}
	string getName() {
		return "Легковой автомобиль";
	}
	void printInfo();
	void changeData();
	void WriteInFile(string Name, string path);
};

int Program();

void Ex1();

void Ex2();

void Ex3();