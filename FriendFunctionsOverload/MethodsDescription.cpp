#include "Header.h"

void String::SetString() {
	if (str != NULL) {
		delete[] str;
	}
	char s[100];
	cout << "Введите строку:" << endl;
	cin.getline(s, 100);
	length = strlen(s) + 1;
	str = new char[length];
	strcpy_s(str, length, s);
	WriteInFile(str);
}

void String::SetString1(char* s) {
	if (str != NULL) {
		delete[] str;
	}
	length = strlen(s) + 1;
	str = new char[length];
	strcpy_s(str, length, s);
	WriteInFile(str);
}

void String::DisplayString() {
	if (str == NULL) {
		cout << "Строка не введена!" << endl;
		return;
	}
	cout << str << endl;
}

void WriteInFile(char* stroka) {
	ofstream file;
	file.open("String.txt", ios::app);
	file << "Записанная строка: " << stroka << "\n\n";
	file.close();
}

bool String::operator!() {
	if (str == NULL) {
		return true;
	}
	return false;
}

void String::operator[](int pos) {
	if (pos - 1 >= length || pos - 1 < 0) {
		cout << "\nДанного индекса строки не существует" << endl;
	}
	else {
		cout << endl << str[pos] << endl << endl;
	}
}

void String::operator()(int pos, int length) {
	if (pos - 1 + length >= this->length) {
		cout << "\nВы вышли за пределы строки!" << endl << endl;
	}
	else if (length <= 0) {
		cout << "\nВ подстроке может быть только положительное количество символов" << endl << endl;
	}
	else {
		char* temp = new char[length + 1];
		int i = 0;
		for (; i < length; i++) {
			temp[i] = str[pos + i];
		}
		temp[i] = '\0';
		cout << endl << temp << endl << endl << endl;
	}
}

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}

void Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String* lines = new String[N];
	int n;
	while (1) {
		cout << "1. Заполнить одну строку массива строк" << endl << "2. Вывести массив строк" << endl
			<< "3. Вывести символ строки" << endl << "4. Вывести подстроку строки\n"
			<< "0. Выйти из программы" << endl << endl << "Что желаете выбрать? (1, 2, 3, 4, 0)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			system("cls");
			cout << "Нужно ввести целое число! Повторите ввод:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> n;
			cin.get();
		}
		switch (n) {
		case 1:
		{
			system("cls");
			int i;
			cout << "Какую строку массива хотите заполнить? (0-4)" << endl;
			cin >> i;
			cin.get();
			while (i < 0 || i > 4) {
				cout << "Нужно ввести цифру от 0 до 4! Повторите ввод:" << endl;
				cin >> i;
				cin.get();
			}
			system("cls");
		/*	cout << "Введите строку:" << endl;
			cin >> lines[i];*/
			lines[i].SetString();
			cout << endl;
			//cin.get();
			DeleteConsole();
		}
		break;
		case 2:
			system("cls");
			for (int i = 0; i < N; i++) {
				if (!lines[i]) {
					cout << "Строка пуста\n" << endl;
				}
				else {
					cout << lines[i] << endl << endl;
				}
			}
			DeleteConsole();
			break;
		case 3:
		{
			system("cls");
			int i;
			cout << "Выберите строку (1-5)" << endl;
			cin >> i;
			cin.get();
			while (i < 1 || i > 5 || !lines[i - 1]) {
				system("cls");
				if (i < 1 || i > 5) {
					cout << "Нужно ввести цифру от 1 до 5! Повторите ввод:" << endl;
					cin >> i;
					cin.get();
				}
				else if (!lines[i - 1]) {
					cout << "Строка не введена!\n" << endl;
					break;
				}
			}
			if (!lines[i - 1]) {
				DeleteConsole();
				break;
			}
			int index;
			cout << "\nВведите индекс символа строки, который хотите вывести" << endl;
			cin >> index;
			cin.get();
			lines[i - 1][index - 1];
			DeleteConsole();
		}
		break;
		case 4:
		{
			system("cls");
			int i;
			cout << "Выберите строку (1-5)" << endl;
			cin >> i;
			cin.get();
			while (i < 1 || i > 5 || !lines[i - 1]) {
				system("cls");
				if (i < 1 || i > 5) {
					cout << "Нужно ввести цифру от 0 до 4! Повторите ввод:" << endl;
					cin >> i;
					cin.get();
				}
				else if (!lines[i - 1]) {
					cout << "Строка не введена!\n" << endl;
					break;
				}
			}
			if (!lines[i - 1]) {
				DeleteConsole();
				break;
			}
			int pos, length;
			cout << "\nВведите позицию с которой начинается подстрока и её длину" << endl;
			cin >> pos >> length;
			cin.get();
			lines[i - 1](pos - 1, length);
			DeleteConsole();
		}
		break;
		case 0:
			return;
			break;
		}
	}
	//String line1;
	//cin >> line1;
	//cout << line1;
	//String* line = new String[5];
	//String stroka1;
	//stroka1.SetString();
	//stroka1.DisplayString();
	//char str[40] = "Кузя учится в университете БГУИР";
	//String stroka2(str);
	//stroka2.DisplayString();
	//stroka2.SetString1(str);
	//stroka2.DisplayString();
	//if (!line[0]) {
	//	line[0].SetString();
	//}
	//cout << endl << stroka2[35] << endl;
	//cout << endl << stroka2(14, 10) << endl;
}

//Пример №1. Использование friend функций
class Student {
	string name;
	int* marks, age;
	int numberOfMarks;
public:
	Student(string name, int numberOfMarks, int age) {// конструктор с параметрами
			this->name = name;
		this->numberOfMarks = numberOfMarks;
		this->marks = new int[numberOfMarks];
		this->age = age;
	}
	friend int maxMark(Student& student);//friend-функция поиска максимальной оценки
		void setAge(int age) { this->age = age; }//метод установки значения поля age
		int getAge() { return age; }//метод получения значения поля age
	void setMarks(int* marks) {//метод установки значения поля marks
		for (int i = 0; i < numberOfMarks; i++)
			this->marks[i] = marks[i];
	};
};
int maxMark(Student& student) {
	int max = student.marks[0];
	for (int i = 1; i < student.numberOfMarks; i++) {
		if (max < student.marks[i]) max = student.marks[i];
	}
	return max;
}
void Ex1() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student student("Северин Иван Иванович", 8, 18); // объявление объекта
		student.setAge(19);
	cout << "Возраст студента:" << student.getAge() << endl;
	int marks[] = { 5,6,9,8,7,10,5,9 };
	student.setMarks(marks);
	cout << "Максимальная оценка в семестре:" << maxMark(student) << endl;//вызов дружественной функции
}


//Пример №3. Использование дружественной функции для задания значений полей класса
class Woman {
private:
	string fullName;//имя
	float weight;//вес
	friend void setData(string, float, Woman&);
	friend void getData(Woman&);
public:
	Woman() {//конструктор
		fullName = "Сидорова Алёна Николаевна";
		weight = 60;
	}
	void showAdvice();
	void setData(string fullName, float weight);
	void getData();
};
void setData(string fullName, float weight, Woman& object) {
	object.fullName = fullName;
	object.weight = weight;
}
void getData(Woman& object) {
	cout << object.fullName << "\t: " << object.weight << " кг" <<
		endl;
}
void Woman::setData(string fullName, float weight) {
	this->fullName = fullName;
	this->weight = weight;
}
void Woman::getData() {
	cout << fullName << "\t: " << weight << " кг" << endl;
}
void Woman::showAdvice() {
	if (weight < 55) {
		cout << "Вам надо потреблять больше каллорий!" << endl;
		cout << "==================================" << endl;
	}
	else if (weight >= 55 && weight <= 65) {
		cout << "Ваш вес в норме!" << endl;
		cout << "==================================" << endl;
	}
	else {
		cout << "Вам надо ограничивать себя в еде!" << endl;
		cout << "==================================" << endl;
	}
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Woman woman1; //weight = 60, fullName = "Сидорова Алёна Николаевна"
		woman1.getData();
	woman1.showAdvice();
	Woman woman2;
	woman2.setData("Петрова Анна Витальевна", 100);
	woman2.getData();
	woman2.showAdvice();
	Woman woman3; //третий объект
	setData("Яркая Инна Сергеевна", 50, woman3);
	getData(woman3);
	woman3.showAdvice();
}


//Пример №5. Перегрузка унарных операторов инкремента и декремента как friend - функций класса
class Integer {
	int value;
public:
	Integer(int value) : value(value) {}
	//унарный +
	friend const Integer& operator+(const Integer& obj);
	//унарный -
	friend const Integer& operator-(const Integer& obj);
	//префиксный инкремент
	friend const Integer& operator++(Integer& obj);
	//постфиксный инкремент
	friend const Integer operator++(Integer& obj, int);
	//префиксный декремент
	friend const Integer& operator--(Integer& obj);
	//постфиксный декремент
	friend const Integer operator--(Integer& obj, int);
	friend ostream& operator<<(ostream& cout, Integer& obj) {
		cout << obj.value;
		return cout;
	}
};
//унарный плюс ничего не изменяет, он возвращает значение операнда
const Integer& operator+(const Integer& obj) { return obj.value; }
//унарный минус изменяет значение знака операнда на противоположный
const Integer& operator-(const Integer& obj) {
	return Integer(-obj.value);
}
//префиксная версия инкремента возвращает значение после инкрементации
const Integer& operator++(Integer& obj) {
	return Integer(++obj.value);
}
//постфиксная версия инкремента возвращает значение до инкрементации
const Integer operator++(Integer& obj, int) {
	Integer oldValue(obj.value);
	obj.value++;
	return oldValue;
}
//префиксная версия декремента возвращает значение после декрементации
const Integer& operator--(Integer& obj) {
	return Integer(--obj.value);
}
//постфиксная версия возвращает значение до декрементации
const Integer operator--(Integer& obj, int) {
	Integer oldValue(obj.value);
	obj.value--;
	return oldValue;
}
void Ex5() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Integer integer1(10), integer2(20), tempInteger(0);
	tempInteger = ++integer1;
	cout << "Префиксная инкрементация integer1:" << integer1 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = integer1++;
	cout << "Постфиксная инкрементация integer1:" << integer1 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = --integer2;
	cout << "Префиксная декрементация integer2:" << integer2 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = integer2--;
	cout << "Постфиксная декрементация integer2:" << integer2 << endl;
	cout << "tempInteger:" << tempInteger << endl;
}