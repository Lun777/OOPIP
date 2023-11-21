#include "Header.h"

void Array::setValues() {											// заполняем массив значениями
	cout << "Заполните массив:" << endl;
	if (!p_arr) {
		cout << "Память под массив не выделена. Выделите память\n";
		cout << "Введите размер массива:\n";
		cin >> size;
		p_arr = new float[size];
	}
	//cout << "\nВведите массив:\n";
	for (int i = 0; i < size; i++) {
		cin >> p_arr[i];
		while (!cin || (getchar() != '\n')) {
			cout << "Некорректный ввод данных! Необходимо вводить вещественные числа! Повторите ввод:" << endl;		//Проверяем на ввод целого числа
			cin.clear();
			rewind(stdin);
			cin >> p_arr[i];																					//Повторяем ввод если считано не целочисленное значение
		}
	}
	cout << endl;
}

void Array::displayArray() {										// выводим массив
	cout << "Введённый массив:\n" << endl;
	for (int i = 0; i < size; i++) {
		cout << p_arr[i] << " ";
	}
	cout << endl << endl << endl;
}

void Array::crossArray(Array arr1, Array arr2) {		// находим пересечение двух массивов
	int i, j, l, p, m = 0;
	float* p_arr3;
	if (arr1.size > arr2.size) {									// проверяем какой массив меньше
		p_arr3 = new float[arr2.size];							// под массив пересечения выделяем столько памяти сколько выделено в меньшем массиве
	}
	else {
		p_arr3 = new float[arr1.size];
	}
	for (i = 0; i < arr1.size; i++) {
		for (j = 0; j < arr2.size; j++) {
			if (arr2.p_arr[j] == arr1.p_arr[i]) {				// находим одинаковый элемент в двух массивах
				p = 0;
				for (l = 0; l < m; l++) {
					if (arr2.p_arr[j] == p_arr3[l]) {			// проверяем есть ли уже этот элемент в массиве пересечения
						p = 1;
						break;
					}
				}
				if (p == 0) {
					p_arr3[m++] = arr2.p_arr[j];				// если нет такого элемента, то добавляем его в массив и увеличиваем его количество элементов (p) на 1
				}
			}
		}
	}
	if (m != 0) {
		cout << "\nПересечение массивов:\n" << endl;
		for (l = 0; l < m; l++) {
			cout << p_arr3[l] << " ";
		}
		cout << endl << endl;
	}
	else {
		cout << "\nНет общих элементов!\n" << endl;
	}
}

void Array::concatArray(Array arr1, Array arr2) {		// находим объединение двух массивов
	int i, j, l, p, m = 0;
	float* p_arr3;
	p_arr3 = new float[arr1.size + arr2.size];						// под массив объединения выделяем столько памяти сколько в двух массивах в сумме
	for (i = 0; i < arr1.size; i++) {
		p = 0;
		for (l = 0; l < m; l++) {
			if (arr1.p_arr[i] == p_arr3[l]) {						// проверяем есть ли такой элемент в массиве объединения
				p = 1;
				break;
			}
		}
		if (p == 0) {
			p_arr3[m++] = arr1.p_arr[i];							// если нет такого элемента, то добавляем его в массив и увеличиваем его количество элементов на 1
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
		cout << "\nОбъединение массивов:\n" << endl;
		for (l = 0; l < m; l++) {
			cout << p_arr3[l] << " ";
		}
		cout << endl << endl;
	}
	else {
		cout << "Массивы пусты!\n" << endl;
	}
}

void Array::WriteInFile() {										// запись в файл
	ofstream ThisFile;
	ThisFile.open("Array.txt", ios::app);
	if (ThisFile.is_open()) {
		ThisFile << "Размер: " << size << "\n Значения массива: ";
		for (int i = 0; i < size; i++) {
			ThisFile << p_arr[i] << " ";
		}
		ThisFile << "\n\n";
	}
	else {
		cout << "Файл не удалось открыть\n";
	}
	ThisFile.close();
}

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
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
	cout << "Введите размер массива объектов" << endl;
	cin >> ObjArrSize;
	while (!cin || (getchar() != '\n') || ObjArrSize < 1) {
		cout << "Нужно ввести целое число больше нуля! Повторите ввод:" << endl;
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
		cout << "1. Заполнить массив объектов" << endl << "2. Вывести массив объектов" << endl
			<< "3. Найти пересечение объектов" << endl << "4. Найти объединение объектов\n"
			<< "5. Выйти из программы" << endl << "Что желаете выбрать? (1, 2, 3, 4, 5)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> n;
		}
		switch (n) {
		case 1:
			//int size;
			//cout << "\nЗаполните массив объектов:\n";
			//cin >> size;
			//Array* p_Obj = new Array(size);
			system("cls");
			for (int i = 0; i < ObjArrSize; i++) {										// проходим по все объектам в цикле
				//int size;
				//cout << "Введите размер массива" << endl;
				//cin >> size;
				//arr[i] = Array(size);
				p_Obj[i].setValues();													// заполняем объекты массивами целых значений		
				p_Obj[i].WriteInFile();													// записываем объекты в файл
				cout << endl;
			}
			a = 1;
			break;
		case 2:
			system("cls");
			if (a == 1) {
				for (int i = 0; i < ObjArrSize; i++) {									// цикл по массиву объектов
					p_Obj[i].displayArray();											// выводим массив объектов на экран
				}
				DeleteConsole();													// очищаем консоль от текста
			}
			else {
				cout << "Массив объектов не введён\n\n";
				DeleteConsole();
			}
			break;
		case 3:
			system("cls");
			if (a == 1) {
				cout << "Пересечение каких объектов хотите найти?\n";
				int x, y;
				cin >> x >> y;																			// номер объекта (нумерование происходит от 1 до ObjArrSize включительно)
				while (x > ObjArrSize || x < 1 || y > ObjArrSize || y < 1) {							// проверка на попадание в диапазон
					cout << "\nОбъекта(-ов) с таким(-и) индексом(-ами) не существует!" << endl;			
					cin >> x;
					getchar();
					cin >> y;
					cout << endl;
				}
				test_arr.crossArray(p_Obj[x - 1], p_Obj[y - 1]);										// формирование массива пересечения двух других объектов
				getchar();
				DeleteConsole();
			}
			else {
				cout << "Массив объектов не введён\n\n";
				DeleteConsole();
			}
			break;
		case 4:
			system("cls");
			if (a == 1) {
				cout << "Объединение каких объектов хотите найти?\n";
				int x, y;
				cin >> x >> y;
				while (x > ObjArrSize || x < 1 || y > ObjArrSize || y < 1) {							// тот же самый цикл что и в массиве пересечений
					//cin.clear();
					cout << "\nОбъекта(-ов) с таким(-и) индексом(-ами) не существует!" << endl;			
					cin >> x;
					getchar();
					cin >> y;
					getchar();
					cout << endl;
				}
				test_arr.concatArray(p_Obj[x - 1], p_Obj[y - 1]);										// нахождения массива объединения двух массивов
				getchar();
				DeleteConsole();
			}
			else {
				cout << "Массив объектов не введён\n\n";
				DeleteConsole();
			}
			break;
		case 5:																							// выход из программы
			return 0;
			break;
		}
	}
}



//Пример №1. Пример использования данных-компонентов и компонентовфункци
struct Point {// объявление структуры
	int x, y;
	void setPixel(int, int);//функция для установления значения переменных x и y
	void getPixel(int*, int*);//функция для получения значения x и y 
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

//Пример №2. Пример использования атрибутов доступа к элементам класса 
class String {
	string str;//поле с атрибутом доступа private
public:
	void setString(const char*);//метод инициализации строки
	void displayString();//метотод отображения строки на экране
	string returnString();//метод возврата строки 
};
void String::setString(const char* newString) {
	str = newString;//копирование содержимого newString в string
}
void String::displayString() { cout << str << endl; }
string String::returnString() { return str; }
void Ex2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String string;//объявление объекта типа String
	string.setString("Первая очередь Минского метрополитена открылась в 1984 году.");
	cout << "Отображение строки вызовом метода displayString(): " << endl;
	string.displayString();
	cout << "Отображение строки вызовом метода returnString(): " << endl;
	cout << string.returnString() << endl;
}

//Пример №3. Использование конструктора
class Game {
	int number;
	string name;
public:
	Game() {//конструктор без параметров
		name = "Слова из слова";
		number = 0;
	}
	Game(string name) {//конструктор с одним параметром
		this->name = name;
		this->number = 50;
	}
	Game(string name, int number) {//конструктор с двумя параметрами
		this->name = name;
		this->number = number;
	}
	Game(int number) {//конструктор с одним параметром 
		this->name = "no name";
		this->number = number;
	}
	void printGameData();
};
void Game::printGameData() {
	cout << "Номер игры \"" << name << "\" равен = " << number << endl;
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game game1;//вызов конструктора без параметров
	Game game2("Скайдом");//вызов конструктора с параметром типа "string"
	Game game3("Bubble hit", 100);//вызов конструктора с двумя параметрами
	Game game4(200);//вызов конструктора с параметром типа "int"
	game1.printGameData();
	game2.printGameData();
	game3.printGameData();
	game4.printGameData();
}

//Пример №4. Использование конструктора по умолчанию
class Time {
public:
	Time(int = 0, int = 0, int = 0);//конструктор со значениями параметров по умолчанию(by default)
	void setTime(int, int, int);//установка времени
	void printTime();//вывод информации о времени
private:
	int hours;//0–23 
	int minutes;//0–59 
	int seconds;//0–59 
};
//Конструктор инициализирует поля класса полученными аргументами 
Time::Time(int hours, int minutes, int seconds) {
	setTime(hours, minutes, seconds);
}
//Выполнение проверки корректности значений данных, установка неверных значений в 0
void Time::setTime(int hours, int minutes, int seconds) {
	this->hours = (hours >= 0 && hours < 24) ? hours : 0;
	this->minutes = (minutes >= 0 && minutes < 60) ? minutes : 0;
	this->seconds = (seconds >= 0 && seconds < 60) ? seconds : 0;
}
//вывод информации о времени
void Time::printTime() {
	cout << ((hours == 0 || hours == 12) ? 12 : hours % 12)
		<< ":" << (minutes < 10 ? "0" : "") << minutes
		<< ":" << (seconds < 10 ? "0" : "") << seconds
		<< (hours < 12 ? " AM" : " PM");
}
void Ex4() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Time t1,//вызов конструктора по умолчанию без передачи аргументов
		t2(2),//вызов конструктора по умолчанию с указанием часов, минуты и секунды определены значениями по умолчанию
		t3(21, 34),//вызов конструктора по умолчанию с указанием часов и минут, секунды определены значением по умолчанию
		t4(12, 25, 42),//вызов конструктора по умолчанию с указанием всех значений параметров
		t5(27, 74, 99);//вызов конструктора по умолчанию с указанием всех неверных значений параметров
	cout << "Создание объекта конструктором по умолчанию без передачи аргументов: " << endl;
	t1.printTime();
	cout << "\nСоздание объекта конструктором по умолчанию с указанием часов, минуты и секунды определены значениями по умолчанию :" << endl;
	t2.printTime();
	cout << "\nСоздание объекта конструктором по умолчанию с указанием часов и минут, секунды определены значениями по умолчанию : " << endl;
	t3.printTime();
	cout << "\nСоздание объекта конструктором по умолчанию с указанием всех значений параметров : " << endl;
	t4.printTime();
	cout << "\nСоздание объекта конструктором по умолчанию с указанием всех неверных значений параметров : " << endl;
	t5.printTime();
}

//Пример №6. Использование деструктора
class DandyGame {
	int gameNumber;
	string name;
	int* participantsNumbers;
public:
	DandyGame(string name);//прототип конструктора 
	~DandyGame();//прототип деструктора 
	void displayName();
};
DandyGame::DandyGame(string name) {//реализация конструктора
	cout << "Работает конструктор....." << endl;
	this->name = name;
	gameNumber = 50;
	participantsNumbers = new int[10];
}
void DandyGame::displayName() {//реализация деструктора
	cout << "имя игры: \"" << name << "\"" << endl;
}
DandyGame::~DandyGame() {//определение деструктора 
	cout << "Работает деструктор....." << endl;
	delete participantsNumbers;
}
void Ex6() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DandyGame game1("Super Mario Bros");//инициализация объекта game1
	DandyGame game2("La formica");//инициализация объекта game2 
	game1.displayName();//вызов метода displayName()
	game2.displayName();//вызов метода displayName()
}

//Пример №7. Использование конструкторов и деструктора. Разработан класс вектор(одномерный динамический массив).
class Vector {
	float* arr;//вектор (одномерный массив) 
	int size;//размерность вектора 
public:
	Vector();//конструктор без параметров 
	Vector(int, float*);//конструктор с двумя параметрами 
	~Vector();//деструктор 
	void setValues();//метод инициализация вектора 
	void printVector();//вывод элементов вектора на экран 
	float findMax();//нахождения максимума в векторе 
};
Vector::Vector() : size(0), arr(0) {}//конструктор без параметров 
Vector::Vector(int size, float* arr) {//конструктор с двумя параметрами
	this->size = size;//инициализация размерности 
	this->arr = new float[this->size];//выделение памяти под вектор 
	for (int i = 0; i < this->size; i++) *(this->arr + i) = *(arr + i);
}
Vector :: ~Vector() { delete[] arr; }
void Vector::setValues() {
	if (!arr) {
		cout << "Не выделена память под вектор," << endl;
		cout << "введите размерность вектора: " << endl;
		cin >> size;
		arr = new float[size];
	}
	cout << "Введите элементы в вектор" << endl;
	for (int i = 0; i < size; i++) cin >> *(arr + i);
}
void Vector::printVector() {
	if (!arr) {
		cout << "Вектор пуст!" << endl;
		return;
	}
	for (int i = 0; i < size; i++) cout << setw(4) << *(arr + i);
	cout << endl;
}
float Vector::findMax() {
	float max = *arr;//инициализация переменной первым элементом массива
	for (int i = 0; i < size; i++)
		if (max < *(arr + i))
			max = *(arr + i);
	return max;
}
void Ex7() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vector v1;//вызывается конструктор без параметров 
	float arr[] = { 2.5, 1.6, 6.7, 4.8, 5.6 };//объявление и инициализация массива
	Vector v2((sizeof(arr) / sizeof(float)), arr);//вызов конструктора с параметрами
	v1.setValues();//инициализация объекта v1 
	cout << "Вектор v1: " << endl;
	v1.printVector();//вывод содержимого объекта v1 
	cout << "Максимальное число в v1 = " << v1.findMax() << endl;
	cout << "Вектор v2: " << endl;
	v2.printVector();//вывод содержимого объекта v2 
	cout << "Максимальное число в v2 = " << v2.findMax() << endl;
}

//Пример №8. Использование статических методов и полей класса
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
	cout << "Первоначальное количество объектов: " <<
		Box::getObjectsCount() << endl;
	Box box1(3.3, 1.2, 1.5);// create box1
	Box box2(8.5, 6.0, 2.0);// create box2
	// Print total number of objects after creating object
	cout << "Конечное количество объектов: " <<
		box1.getObjectsCount() << endl;
}

//Пример №9. Использование константных методов класса
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
	cout << "Месяц в объекте date1: " << date1.getMonth() << endl;
	cout << "Месяц в объекте date2: " << date2.getMonth() << endl;
}