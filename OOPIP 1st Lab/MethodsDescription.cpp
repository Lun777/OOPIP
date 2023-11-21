#include "Header.h"

void Array::setValues() {											// ��������� ������ ����������
	cout << "��������� ������:" << endl;
	if (!p_arr) {
		cout << "������ ��� ������ �� ��������. �������� ������\n";
		cout << "������� ������ �������:\n";
		cin >> size;
		p_arr = new float[size];
	}
	//cout << "\n������� ������:\n";
	for (int i = 0; i < size; i++) {
		cin >> p_arr[i];
		while (!cin || (getchar() != '\n')) {
			cout << "������������ ���� ������! ���������� ������� ������������ �����! ��������� ����:" << endl;		//��������� �� ���� ������ �����
			cin.clear();
			rewind(stdin);
			cin >> p_arr[i];																					//��������� ���� ���� ������� �� ������������� ��������
		}
	}
	cout << endl;
}

void Array::displayArray() {										// ������� ������
	cout << "�������� ������:\n" << endl;
	for (int i = 0; i < size; i++) {
		cout << p_arr[i] << " ";
	}
	cout << endl << endl << endl;
}

void Array::crossArray(Array arr1, Array arr2) {		// ������� ����������� ���� ��������
	int i, j, l, p, m = 0;
	float* p_arr3;
	if (arr1.size > arr2.size) {									// ��������� ����� ������ ������
		p_arr3 = new float[arr2.size];							// ��� ������ ����������� �������� ������� ������ ������� �������� � ������� �������
	}
	else {
		p_arr3 = new float[arr1.size];
	}
	for (i = 0; i < arr1.size; i++) {
		for (j = 0; j < arr2.size; j++) {
			if (arr2.p_arr[j] == arr1.p_arr[i]) {				// ������� ���������� ������� � ���� ��������
				p = 0;
				for (l = 0; l < m; l++) {
					if (arr2.p_arr[j] == p_arr3[l]) {			// ��������� ���� �� ��� ���� ������� � ������� �����������
						p = 1;
						break;
					}
				}
				if (p == 0) {
					p_arr3[m++] = arr2.p_arr[j];				// ���� ��� ������ ��������, �� ��������� ��� � ������ � ����������� ��� ���������� ��������� (p) �� 1
				}
			}
		}
	}
	if (m != 0) {
		cout << "\n����������� ��������:\n" << endl;
		for (l = 0; l < m; l++) {
			cout << p_arr3[l] << " ";
		}
		cout << endl << endl;
	}
	else {
		cout << "\n��� ����� ���������!\n" << endl;
	}
}

void Array::concatArray(Array arr1, Array arr2) {		// ������� ����������� ���� ��������
	int i, j, l, p, m = 0;
	float* p_arr3;
	p_arr3 = new float[arr1.size + arr2.size];						// ��� ������ ����������� �������� ������� ������ ������� � ���� �������� � �����
	for (i = 0; i < arr1.size; i++) {
		p = 0;
		for (l = 0; l < m; l++) {
			if (arr1.p_arr[i] == p_arr3[l]) {						// ��������� ���� �� ����� ������� � ������� �����������
				p = 1;
				break;
			}
		}
		if (p == 0) {
			p_arr3[m++] = arr1.p_arr[i];							// ���� ��� ������ ��������, �� ��������� ��� � ������ � ����������� ��� ���������� ��������� �� 1
		}
	}
	for (j = 0; j < arr2.size; j++) {
		p = 0;
		for (l = 0; l < m; l++) {
			if (arr2.p_arr[j] == p_arr3[l]) {
				p = 1;
				break;
			}
		}
		if (p == 0) {
			p_arr3[m++] = arr2.p_arr[j];
		}
	}
	if (m != 0) {
		cout << "\n����������� ��������:\n" << endl;
		for (l = 0; l < m; l++) {
			cout << p_arr3[l] << " ";
		}
		cout << endl << endl;
	}
	else {
		cout << "������� �����!\n" << endl;
	}
}

void Array::WriteInFile() {										// ������ � ����
	ofstream ThisFile;
	ThisFile.open("Array.txt", ios::app);
	if (ThisFile.is_open()) {
		ThisFile << "������: " << size << "\n �������� �������: ";
		for (int i = 0; i < size; i++) {
			ThisFile << p_arr[i] << " ";
		}
		ThisFile << "\n\n";
	}
	else {
		cout << "���� �� ������� �������\n";
	}
	ThisFile.close();
}

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}



int Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*int mas[] = { 2,4,4,];
	Array* array = {
		new Array();
		new Array(2);
		new Array();
		new Array();
		new Array();
			};*/
	int ObjArrSize;
	cout << "������� ������ ������� ��������" << endl;
	cin >> ObjArrSize;
	while (!cin || (getchar() != '\n') || ObjArrSize < 1) {
		cout << "����� ������ ����� ����� ������ ����! ��������� ����:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> ObjArrSize;
	}
	Array* p_Obj = new Array[ObjArrSize];
	//Array* arr = new Array[5];
	Array test_arr(0);
	system("cls");
	//for (int i = 0; i < 10; i++) {
	//	arr[i].setValues();
	//}
	//Array a1r = Array(4);
	//Array test_arr;


	int n, a = 0;
	while (1) {
		cout << "1. ��������� ������ ��������" << endl << "2. ������� ������ ��������" << endl
			<< "3. ����� ����������� ��������" << endl << "4. ����� ����������� ��������\n"
			<< "5. ����� �� ���������" << endl << "��� ������� �������? (1, 2, 3, 4, 5)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> n;
		}
		switch (n) {
		case 1:
			//int size;
			//cout << "\n��������� ������ ��������:\n";
			//cin >> size;
			//Array* p_Obj = new Array(size);
			system("cls");
			for (int i = 0; i < ObjArrSize; i++) {										// �������� �� ��� �������� � �����
				//int size;
				//cout << "������� ������ �������" << endl;
				//cin >> size;
				//arr[i] = Array(size);
				p_Obj[i].setValues();													// ��������� ������� ��������� ����� ��������		
				p_Obj[i].WriteInFile();													// ���������� ������� � ����
				cout << endl;
			}
			a = 1;
			break;
		case 2:
			system("cls");
			if (a == 1) {
				for (int i = 0; i < ObjArrSize; i++) {									// ���� �� ������� ��������
					p_Obj[i].displayArray();											// ������� ������ �������� �� �����
				}
				DeleteConsole();													// ������� ������� �� ������
			}
			else {
				cout << "������ �������� �� �����\n\n";
				DeleteConsole();
			}
			break;
		case 3:
			system("cls");
			if (a == 1) {
				cout << "����������� ����� �������� ������ �����?\n";
				int x, y;
				cin >> x >> y;																			// ����� ������� (����������� ���������� �� 1 �� ObjArrSize ������������)
				while (x > ObjArrSize || x < 1 || y > ObjArrSize || y < 1) {							// �������� �� ��������� � ��������
					cout << "\n�������(-��) � �����(-�) ��������(-���) �� ����������!" << endl;			
					cin >> x;
					getchar();
					cin >> y;
					cout << endl;
				}
				test_arr.crossArray(p_Obj[x - 1], p_Obj[y - 1]);										// ������������ ������� ����������� ���� ������ ��������
				getchar();
				DeleteConsole();
			}
			else {
				cout << "������ �������� �� �����\n\n";
				DeleteConsole();
			}
			break;
		case 4:
			system("cls");
			if (a == 1) {
				cout << "����������� ����� �������� ������ �����?\n";
				int x, y;
				cin >> x >> y;
				while (x > ObjArrSize || x < 1 || y > ObjArrSize || y < 1) {							// ��� �� ����� ���� ��� � � ������� �����������
					//cin.clear();
					cout << "\n�������(-��) � �����(-�) ��������(-���) �� ����������!" << endl;			
					cin >> x;
					getchar();
					cin >> y;
					getchar();
					cout << endl;
				}
				test_arr.concatArray(p_Obj[x - 1], p_Obj[y - 1]);										// ���������� ������� ����������� ���� ��������
				getchar();
				DeleteConsole();
			}
			else {
				cout << "������ �������� �� �����\n\n";
				DeleteConsole();
			}
			break;
		case 5:																							// ����� �� ���������
			return 0;
			break;
		}
	}
}



//������ �1. ������ ������������� ������-����������� � �����������������
struct Point {// ���������� ���������
	int x, y;
	void setPixel(int, int);//������� ��� ������������ �������� ���������� x � y
	void getPixel(int*, int*);//������� ��� ��������� �������� x � y 
};
void Ex1() {
	setlocale(LC_ALL, "Russian");
	int x, y;
	Point point, * pointer;
	pointer = &point;
	point.setPixel(50, 100);
	pointer->getPixel(&x, &y);
	cout << "x = " << x << ", y = " << y << endl;
}
void Point::setPixel(int a, int b) {
	x = a;
	y = b;
}
void Point::getPixel(int* a, int* b) {
	*a = x;
	*b = y;
}

//������ �2. ������ ������������� ��������� ������� � ��������� ������ 
class String {
	string str;//���� � ��������� ������� private
public:
	void setString(const char*);//����� ������������� ������
	void displayString();//������� ����������� ������ �� ������
	string returnString();//����� �������� ������ 
};
void String::setString(const char* newString) {
	str = newString;//����������� ����������� newString � string
}
void String::displayString() { cout << str << endl; }
string String::returnString() { return str; }
void Ex2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String string;//���������� ������� ���� String
	string.setString("������ ������� �������� ������������� ��������� � 1984 ����.");
	cout << "����������� ������ ������� ������ displayString(): " << endl;
	string.displayString();
	cout << "����������� ������ ������� ������ returnString(): " << endl;
	cout << string.returnString() << endl;
}

//������ �3. ������������� ������������
class Game {
	int number;
	string name;
public:
	Game() {//����������� ��� ����������
		name = "����� �� �����";
		number = 0;
	}
	Game(string name) {//����������� � ����� ����������
		this->name = name;
		this->number = 50;
	}
	Game(string name, int number) {//����������� � ����� �����������
		this->name = name;
		this->number = number;
	}
	Game(int number) {//����������� � ����� ���������� 
		this->name = "no name";
		this->number = number;
	}
	void printGameData();
};
void Game::printGameData() {
	cout << "����� ���� \"" << name << "\" ����� = " << number << endl;
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game game1;//����� ������������ ��� ����������
	Game game2("�������");//����� ������������ � ���������� ���� "string"
	Game game3("Bubble hit", 100);//����� ������������ � ����� �����������
	Game game4(200);//����� ������������ � ���������� ���� "int"
	game1.printGameData();
	game2.printGameData();
	game3.printGameData();
	game4.printGameData();
}

//������ �4. ������������� ������������ �� ���������
class Time {
public:
	Time(int = 0, int = 0, int = 0);//����������� �� ���������� ���������� �� ���������(by default)
	void setTime(int, int, int);//��������� �������
	void printTime();//����� ���������� � �������
private:
	int hours;//0�23 
	int minutes;//0�59 
	int seconds;//0�59 
};
//����������� �������������� ���� ������ ����������� ����������� 
Time::Time(int hours, int minutes, int seconds) {
	setTime(hours, minutes, seconds);
}
//���������� �������� ������������ �������� ������, ��������� �������� �������� � 0
void Time::setTime(int hours, int minutes, int seconds) {
	this->hours = (hours >= 0 && hours < 24) ? hours : 0;
	this->minutes = (minutes >= 0 && minutes < 60) ? minutes : 0;
	this->seconds = (seconds >= 0 && seconds < 60) ? seconds : 0;
}
//����� ���������� � �������
void Time::printTime() {
	cout << ((hours == 0 || hours == 12) ? 12 : hours % 12)
		<< ":" << (minutes < 10 ? "0" : "") << minutes
		<< ":" << (seconds < 10 ? "0" : "") << seconds
		<< (hours < 12 ? " AM" : " PM");
}
void Ex4() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Time t1,//����� ������������ �� ��������� ��� �������� ����������
		t2(2),//����� ������������ �� ��������� � ��������� �����, ������ � ������� ���������� ���������� �� ���������
		t3(21, 34),//����� ������������ �� ��������� � ��������� ����� � �����, ������� ���������� ��������� �� ���������
		t4(12, 25, 42),//����� ������������ �� ��������� � ��������� ���� �������� ����������
		t5(27, 74, 99);//����� ������������ �� ��������� � ��������� ���� �������� �������� ����������
	cout << "�������� ������� ������������� �� ��������� ��� �������� ����������: " << endl;
	t1.printTime();
	cout << "\n�������� ������� ������������� �� ��������� � ��������� �����, ������ � ������� ���������� ���������� �� ��������� :" << endl;
	t2.printTime();
	cout << "\n�������� ������� ������������� �� ��������� � ��������� ����� � �����, ������� ���������� ���������� �� ��������� : " << endl;
	t3.printTime();
	cout << "\n�������� ������� ������������� �� ��������� � ��������� ���� �������� ���������� : " << endl;
	t4.printTime();
	cout << "\n�������� ������� ������������� �� ��������� � ��������� ���� �������� �������� ���������� : " << endl;
	t5.printTime();
}

//������ �6. ������������� �����������
class DandyGame {
	int gameNumber;
	string name;
	int* participantsNumbers;
public:
	DandyGame(string name);//�������� ������������ 
	~DandyGame();//�������� ����������� 
	void displayName();
};
DandyGame::DandyGame(string name) {//���������� ������������
	cout << "�������� �����������....." << endl;
	this->name = name;
	gameNumber = 50;
	participantsNumbers = new int[10];
}
void DandyGame::displayName() {//���������� �����������
	cout << "��� ����: \"" << name << "\"" << endl;
}
DandyGame::~DandyGame() {//����������� ����������� 
	cout << "�������� ����������....." << endl;
	delete participantsNumbers;
}
void Ex6() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DandyGame game1("Super Mario Bros");//������������� ������� game1
	DandyGame game2("La formica");//������������� ������� game2 
	game1.displayName();//����� ������ displayName()
	game2.displayName();//����� ������ displayName()
}

//������ �7. ������������� ������������� � �����������. ���������� ����� ������(���������� ������������ ������).
class Vector {
	float* arr;//������ (���������� ������) 
	int size;//����������� ������� 
public:
	Vector();//����������� ��� ���������� 
	Vector(int, float*);//����������� � ����� ����������� 
	~Vector();//���������� 
	void setValues();//����� ������������� ������� 
	void printVector();//����� ��������� ������� �� ����� 
	float findMax();//���������� ��������� � ������� 
};
Vector::Vector() : size(0), arr(0) {}//����������� ��� ���������� 
Vector::Vector(int size, float* arr) {//����������� � ����� �����������
	this->size = size;//������������� ����������� 
	this->arr = new float[this->size];//��������� ������ ��� ������ 
	for (int i = 0; i < this->size; i++) *(this->arr + i) = *(arr + i);
}
Vector :: ~Vector() { delete[] arr; }
void Vector::setValues() {
	if (!arr) {
		cout << "�� �������� ������ ��� ������," << endl;
		cout << "������� ����������� �������: " << endl;
		cin >> size;
		arr = new float[size];
	}
	cout << "������� �������� � ������" << endl;
	for (int i = 0; i < size; i++) cin >> *(arr + i);
}
void Vector::printVector() {
	if (!arr) {
		cout << "������ ����!" << endl;
		return;
	}
	for (int i = 0; i < size; i++) cout << setw(4) << *(arr + i);
	cout << endl;
}
float Vector::findMax() {
	float max = *arr;//������������� ���������� ������ ��������� �������
	for (int i = 0; i < size; i++)
		if (max < *(arr + i))
			max = *(arr + i);
	return max;
}
void Ex7() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vector v1;//���������� ����������� ��� ���������� 
	float arr[] = { 2.5, 1.6, 6.7, 4.8, 5.6 };//���������� � ������������� �������
	Vector v2((sizeof(arr) / sizeof(float)), arr);//����� ������������ � �����������
	v1.setValues();//������������� ������� v1 
	cout << "������ v1: " << endl;
	v1.printVector();//����� ����������� ������� v1 
	cout << "������������ ����� � v1 = " << v1.findMax() << endl;
	cout << "������ v2: " << endl;
	v2.printVector();//����� ����������� ������� v2 
	cout << "������������ ����� � v2 = " << v2.findMax() << endl;
}

//������ �8. ������������� ����������� ������� � ����� ������
class Box {
public:
	Box(float length = 2.0, float width = 2.0, float height = 2.0) {
		cout << "The constructor was called" << endl;
		this->length = length;
		this->width = width;
		this->height = height;
		objectCount++;// Increase every time object is created
	}
	float volume() { return length * width * height; }
	static int getObjectsCount() { return objectCount; }
private:
	static int objectCount;
	float length;
	float width;
	float height;
};
// Initialization static field of class Box
int Box::objectCount = 0;
void Ex8() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Print total number of objects before creating object
	cout << "�������������� ���������� ��������: " <<
		Box::getObjectsCount() << endl;
	Box box1(3.3, 1.2, 1.5);// create box1
	Box box2(8.5, 6.0, 2.0);// create box2
	// Print total number of objects after creating object
	cout << "�������� ���������� ��������: " <<
		box1.getObjectsCount() << endl;
}

//������ �9. ������������� ����������� ������� ������
class Date {
public:
	Date(int year = 2022, int month = 1, int day = 1) : year(year),
		month(month), day(day) {}
	int getMonth() const;//A read-only function 
	void setMonth(int mn);//A write function; can't be const 
private:
	int year;
	int month;
	int day;
};
int Date::getMonth() const {
	//month = 0;
	return month;//Doesn't modify anything 
}
void Date::setMonth(int month) {
	this->month = month;//can change class fields 
}
void Ex9() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Date date1;
	Date date2(7, 4, 2020);
	date2.setMonth(8);
	cout << "����� � ������� date1: " << date1.getMonth() << endl;
	cout << "����� � ������� date2: " << date2.getMonth() << endl;
}