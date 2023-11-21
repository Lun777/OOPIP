#include "Header.h"

void Input(int& var) {
	while (var < 0 || !cin || (getchar() != '\n')) {
		if (var < 0) {
			cout << "������������� �������� �����������! ��������� ����:" << endl;

		}
		else {
			cout << "\n������������ ���� ������! ���������� ������ ����� �����! ��������� ����:" << endl;		//��������� �� ���� ������ �����
		}
		cin.clear();
		rewind(stdin);
		cin >> var;																					//��������� ���� ���� ������� �� ������������� ��������
	}
}

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}



void Transport::printInfo() {
	cout << "������ ������� �������: " << EnergyConsumption << " ���*�" << endl;
	cout << "�������� ���������: " << Power << " ���" << endl;
	cout << "��� ��������: " << WorkerFullName << endl;
	cout << "���� ��������: " << WorkExp << " ���" << endl;
	cout << "���������� ����������� ����: " << PassSeats << endl;
	cout << "����� ������������: " << Lifetime << " ���" << endl;
	cout << "������: " << Mileage << " ��" << endl;
	cout << "������: " << Model << endl;
}

void Transport::changeData() {
	cout << "������� ������ �������(�������) (� ���*�): ";
	cin >> EnergyConsumption;
	Input(EnergyConsumption);
	cout << "������� �������� ��������� (� ���): ";
	cin >> Power;
	Input(Power);
	cout << "������� ��� ��������: ";
	getline(cin, WorkerFullName);
	cout << "������� ���� �������� (� �����): ";
	cin >> WorkExp;
	Input(WorkExp);
	cout << "������� ���������� ������������ ����: ";
	cin >> PassSeats;
	Input(PassSeats);
	cout << "������� ���-�� ��� ������������ ���������� (� �����): ";
	cin >> Lifetime;
	Input(Lifetime);
	cout << "������� ������ ������ (� ��): ";
	cin >> Mileage;
	Input(Mileage);
	cout << "������� ������ ������: ";
	getline(cin, Model);
}

void Transport::WriteInFile(string Name, string path) {
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << endl << Name << endl << EnergyConsumption << " ���*�" << endl << Power << " ���" << endl << WorkerFullName << endl << WorkExp << " ���"
			<< endl << PassSeats << endl << Lifetime << " ���" << endl << Mileage << " ��" << endl << Model;
	}
	file.close();
}

void PublicTransport::printInfo() {
	Transport::printInfo();
	cout << "��. ����: " << Entity << endl;
}

void PublicTransport::changeData() {
	Transport::changeData();
	cout << "������� ��. ���� ��������� �����������: ";
	getline(cin, Entity);
}

void PublicTransport::WriteInFile(string Name, string path) {
	Transport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << Entity;
	}
	file.close();
}

void ElecTransport::printInfo() {
	PublicTransport::printInfo();
	cout << "��� �������������: " << Pantograph << endl;
}

void ElecTransport::changeData() {
	PublicTransport::changeData();
	cout << "������� ��� ������������� (��������� ��� �������): ";
	getline(cin, Pantograph);
}

void ElecTransport::WriteInFile(string Name, string path) {
	PublicTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << Pantograph;
	}
	file.close();
}

void Tram::printInfo() {
	ElecTransport::printInfo();
	cout << "��� �������: " << Type << endl;
}

void Tram::changeData() {
	ElecTransport::changeData();
	cout << "������� ��� �������: ";
	getline(cin, Type);
}

void Tram::WriteInFile(string Name, string path) {
	ElecTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << Type;
	}
	file.close();
}

void Minibus::printInfo() {
	PublicTransport::printInfo();
	cout << "��� ��������: " << RouteType << endl;
}

void Minibus::changeData() {
	PublicTransport::changeData();
	cout << "������� ��� �������� (������������ ��� ���������������): ";
	getline(cin, RouteType);
}

void Minibus::WriteInFile(string Name, string path) {
	PublicTransport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << RouteType;
	}
	file.close();
}

void Car::printInfo() {
	Transport::printInfo();
	cout << "���. ����: " << Individual << endl;
}

void Car::changeData() {
	Transport::changeData();
	cout << "������� ���. ���� ��������� �������: ";
	getline(cin, Individual);
}

void Car::WriteInFile(string Name, string path) {
	Transport::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << Individual;
	}
	file.close();
}

void Truck::printInfo() {
	Car::printInfo();
	cout << "����������������: " << CarryingCapacity << " �" << endl;
}

void Truck::changeData() {
	Car::changeData();
	cout << "������� ���������������� ��������� ���������� (� ������): ";
	cin >> CarryingCapacity;
	Input(CarryingCapacity);
}

void Truck::WriteInFile(string Name, string path) {
	Car::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << CarryingCapacity << " �";
	}
	file.close();
}

void Dumper::printInfo() {
	Truck::printInfo();
	cout << "���������, ������� ����� ���������� ��������: ";
	for (int i = 0; i < size; i++) {
		cout << p[i];
		if (i != size - 1) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

void Dumper::changeData() {
	Truck::changeData();
	cout << "������� ���������� �������� ����������, ������� ����� ���������� ��������: ";
	cin >> size;
	Input(size);
	p = new string[size];
	cout << "������� ���������: " << endl;
	for (int i = 0; i < size; i++) {
		getline(cin, p[i]);
	}
}

void Dumper::WriteInFile(string Name, string path) {
	Truck::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl;
		for (int i = 0; i < size; i++) {
			file << p[i];
			if (i != size - 1) {
				file << ", ";
			}
		}
	}
	file.close();
}

void PassengerCar::printInfo() {
	Car::printInfo();
	cout << "����������� ����������� ��������: " << MaxSpeed << " ��/�" << endl;
}

void PassengerCar::changeData() {
	Car::changeData();
	cout << "������� ����������� ����������� �������� �������� ������� (� ��/�): ";
	cin >> MaxSpeed;
	Input(MaxSpeed);
}

void PassengerCar::WriteInFile(string Name, string path) {
	Car::WriteInFile(Name, path);
	ofstream file;
	file.open(path, ios::app);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
	}
	else {
		file << endl << MaxSpeed << " ��/�";
	}
	file.close();
}



int Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Transport* arr[7];														// 1. �������� ��������� �� ������� �����
	arr[0] = new Bus();														// 2. ���������� ��������� �� ������� ����� ����� ������� ��������� ������
	arr[1] = new Trolleybus();												// � �����
	arr[2] = new Tram();													// � �����
	arr[3] = new Minibus();													// � �����
	arr[4] = new Lorry();													// � �����
	arr[5] = new Dumper();													// � �����
	arr[6] = new PassengerCar();											// � �����
	int n;
	while (1) {
		cout << "1. ��������� ������" << endl << "2. ������� ������" << endl
			<< "3. �������� ������� �������" << endl << "0. ����� �� ���������"
			<< endl << endl << "��� ������� �������? (1, 2, 3, 0)\n";
		cin >> n;
		Input(n);
		switch (n) {
		case 1:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << arr[i]->getName() << endl;							// 3. ����� ������������ ������ ������������ � ������� ������ � ���������������� � �������� �������
				arr[i]->changeData();										// ����� ������������ ������ ������������ ����� ����������� �������
				cout << endl;
			}
			DeleteConsole();
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << i + 1 << ". ";
				cout << arr[i]->getName() << endl;
				arr[i]->printInfo();
				if (i != 6) {
					cout << "-------------------------------------------------------------------------------------------------------" << endl;
				}
				else {
					cout << endl;
				}
			}
			DeleteConsole();
			break;
		case 3:
			system("cls");
			for (int i = 0; i < 7; i++) {
				cout << i + 1 << ". ";
				cout << arr[i]->getName() << endl;
				arr[i]->printInfo();
				if (i != 6) {
					cout << "-------------------------------------------------------------------------------------------------------" << endl;
				}
				else {
					cout << endl;
				}
			}
			int k;
			cout << "������� ����� �������, ������� ������ ��������. (1-7)" << endl;
			cin >> k;
			while (k < 1 || k > 7 || !cin || (getchar() != '\n')) {
				if (k < 1 || k > 7) {
					cout << "������� � ����� ������� �� ����������! ��������� ����:" << endl;
				}
				else {
					cout << "����� ������ ����� �����! ��������� ����:" << endl;
				}
				cin.clear();
				rewind(stdin);
				cin >> k;
			}
			cout << endl;
			cout << arr[k - 1]->getName() << endl;
			arr[k - 1]->changeData();
			cout << endl;
			DeleteConsole();
			break;
		case 0:
			for (int i = 0; i < 7; i++) {
				string Name;
				Name = arr[i]->getName();
				arr[i]->WriteInFile(Name, "Transport.txt");

			}
			return 0;
			break;
		default:
			if (n > 3) {
				cout << "������ ������ �� ����������! ��������� ����:" << endl;
				DeleteConsole();
			}
		}
	}
}



//������ �1. ������������� ���������� �� ������� ����� ��� ������� � �������� ����������� �������
class BankAccount { // ������� ����� 
protected:
	float balance;
public:
	BankAccount() { balance = 0; }
	string owner;
	void depositMoney(float sum) { balance += sum; }
	void showBalance() { cout << "balance=" << balance << endl; }
};
class SavingAccount :public BankAccount {// ����������� �����
	float annualInterestRate;
public:
	void withdrawMoney(int sum) {
		//balance = 1000.5;//������, balance � private-���������� ������ BankAccount � �������� ������ ��� ������� � ������������� ������� ������������ ������
			annualInterestRate = 0.5;//������ � ���������� ���� private�� ������ ������
			owner = "N/A";//owner ������������ �� ������ BankAccount � ��������� ������� private � ������� �������� � ������ ������
			balance -= sum;
	}
};
void Ex1() {
	BankAccount* ptrBankAccount, bankAccount;
	SavingAccount* ptrSavingAccount, savingAccount;
	ptrBankAccount = &bankAccount; // ����� ������� �������� ������
	ptrBankAccount->depositMoney(100);// ������ � ������� ����� ���������
		ptrBankAccount = &savingAccount;
	ptrBankAccount->depositMoney(200);//������ � ������� ����� "�������" ���������
		bankAccount.showBalance();
	savingAccount.showBalance();
	cout << "\n";
	//��������� ����� withdrawMoney() �� �������� ������ �������� ������, �� �� ���������� ����� "�������" ���������, � � ����
	//���������� ���������� ���� ���������������, ���� ����� ��������� �� ����������� ���
	ptrSavingAccount = &savingAccount;
	ptrSavingAccount->withdrawMoney(50);
	ptrSavingAccount->showBalance();
}

//������ �2. ������������� ����������� �������
class Shape { // ������� �����
public:
	virtual string getName(void) { return "no name"; }
	virtual float getArea(void) { return 0; }
};
class Rect : public Shape { // ����������� ����� ��������������
	float height, width; // ������� ��������������
public:
	Rect(float height, float width) {
		this->height = height;
		this -> width = width;
	}
	string getName(void) { return "�������������"; }
	float getArea(void) { return height * width; }
};
class Circle : public Shape { // ����������� ����� ������������
	float radius; // ������ ����������
public:
	Circle(float radius) { this->radius = radius; }
	string getName(void) { return "����"; }
	float getArea(void) { return 3.14f * radius * radius; }
};
void Ex2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Shape* ptrShapes[2]; // ������ ���������� �� ������� �����
	Rect rect(3, 4);
	Circle circle(5);
	ptrShapes[0] = &rect;
	ptrShapes[1] = &circle;
	for (int i = 0; i < 2; i++)
		cout << "������� " << ptrShapes[i]->getName() << setw(8) << ptrShapes[i]->getArea() << endl;
}

//������ �3. ������������� ����������� �������
class Student { // ������� �����
protected:
	string specialization; // �������� �������������
	int group; // ����� ������
public:
	Student(string specialization, int group) { // �����������
		this->specialization = specialization;
		this->group = group;
	}
	~Student() { // ����������
		cout << "���������� ������ Student" << endl;
	}
	virtual void print(void); // ���������� ����������� �������
};
class GraduateStudent : public Student { // ����������� �����
	string fullName; // ���
	int marks[4]; // ������ ������
public:
	GraduateStudent(string specialization, long group, string
		fullName, int marks[]) :Student(specialization, group) {
		this->fullName = fullName;
		for (int i = 0; i < 4; i++) this->marks[i] = marks[i];
	}
	~GraduateStudent() {
		cout << "���������� ������ GraduateStudent" << endl;
	}
	void print(void);
};
void Student::print(void) { // ���������� ����������� �������
	cout << setw(10) << "�������������" << setw(10) << "������" <<
		endl;
	cout << setw(10) << specialization << setw(10) << group << endl;
}
void GraduateStudent::print(void) {
	Student::print(); // ����� ������� �������� ������
	cout << setw(10) << "���" << setw(fullName.length() + 3) << " ������" << endl;
		cout << setw(10) << fullName;
	for (int i = 0; i < 4; i++) cout << setw(4) << marks[i];
	cout << endl;
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int marks[] = { 4,5,5,4 }; // ������ ������
	string specialization;
	long group;
	string fullName;
	cout << "������� �������� �������������" << endl;
	getline(cin, specialization, '\n');
	cout << "������� ����� ������" << endl;
	cin >> group;
	cin.ignore(10, '\n');
	cout << "������� ���" << endl;
	getline(cin, fullName, '\n');
	Student student(specialization, group), * ptrStudent;
	GraduateStudent graduateStudent(specialization, group, fullName,
		marks);
	cout << "������:" << endl;
	//ptrStudent =&student; // ��������� ���� �������� ������ ����� ������� ����� ������� �������� ������
		//ptrStudent->print(); // ����� ������� �������� ������
		ptrStudent = &graduateStudent;// ��������� ���� �������� ������ ������ ����� ������� ������������ ������
		ptrStudent->print(); // ����� ������� ������������ ������
}