#include "Header.h"

void String::SetString() {
	if (str != NULL) {
		delete[] str;
	}
	char s[100];
	cout << "������� ������:" << endl;
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
		cout << "������ �� �������!" << endl;
		return;
	}
	cout << str << endl;
}

void WriteInFile(char* stroka) {
	ofstream file;
	file.open("String.txt", ios::app);
	file << "���������� ������: " << stroka << "\n\n";
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
		cout << "\n������� ������� ������ �� ����������" << endl;
	}
	else {
		cout << endl << str[pos] << endl << endl;
	}
}

void String::operator()(int pos, int length) {
	if (pos - 1 + length >= this->length) {
		cout << "\n�� ����� �� ������� ������!" << endl << endl;
	}
	else if (length <= 0) {
		cout << "\n� ��������� ����� ���� ������ ������������� ���������� ��������" << endl << endl;
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
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}

void Program() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String* lines = new String[N];
	int n;
	while (1) {
		cout << "1. ��������� ���� ������ ������� �����" << endl << "2. ������� ������ �����" << endl
			<< "3. ������� ������ ������" << endl << "4. ������� ��������� ������\n"
			<< "0. ����� �� ���������" << endl << endl << "��� ������� �������? (1, 2, 3, 4, 0)\n";
		cin >> n;
		while (!cin || (getchar() != '\n')) {
			system("cls");
			cout << "����� ������ ����� �����! ��������� ����:" << endl;
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
			cout << "����� ������ ������� ������ ���������? (0-4)" << endl;
			cin >> i;
			cin.get();
			while (i < 0 || i > 4) {
				cout << "����� ������ ����� �� 0 �� 4! ��������� ����:" << endl;
				cin >> i;
				cin.get();
			}
			system("cls");
		/*	cout << "������� ������:" << endl;
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
					cout << "������ �����\n" << endl;
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
			cout << "�������� ������ (1-5)" << endl;
			cin >> i;
			cin.get();
			while (i < 1 || i > 5 || !lines[i - 1]) {
				system("cls");
				if (i < 1 || i > 5) {
					cout << "����� ������ ����� �� 1 �� 5! ��������� ����:" << endl;
					cin >> i;
					cin.get();
				}
				else if (!lines[i - 1]) {
					cout << "������ �� �������!\n" << endl;
					break;
				}
			}
			if (!lines[i - 1]) {
				DeleteConsole();
				break;
			}
			int index;
			cout << "\n������� ������ ������� ������, ������� ������ �������" << endl;
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
			cout << "�������� ������ (1-5)" << endl;
			cin >> i;
			cin.get();
			while (i < 1 || i > 5 || !lines[i - 1]) {
				system("cls");
				if (i < 1 || i > 5) {
					cout << "����� ������ ����� �� 0 �� 4! ��������� ����:" << endl;
					cin >> i;
					cin.get();
				}
				else if (!lines[i - 1]) {
					cout << "������ �� �������!\n" << endl;
					break;
				}
			}
			if (!lines[i - 1]) {
				DeleteConsole();
				break;
			}
			int pos, length;
			cout << "\n������� ������� � ������� ���������� ��������� � � �����" << endl;
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
	//char str[40] = "���� ������ � ������������ �����";
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

//������ �1. ������������� friend �������
class Student {
	string name;
	int* marks, age;
	int numberOfMarks;
public:
	Student(string name, int numberOfMarks, int age) {// ����������� � �����������
			this->name = name;
		this->numberOfMarks = numberOfMarks;
		this->marks = new int[numberOfMarks];
		this->age = age;
	}
	friend int maxMark(Student& student);//friend-������� ������ ������������ ������
		void setAge(int age) { this->age = age; }//����� ��������� �������� ���� age
		int getAge() { return age; }//����� ��������� �������� ���� age
	void setMarks(int* marks) {//����� ��������� �������� ���� marks
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
	Student student("������� ���� ��������", 8, 18); // ���������� �������
		student.setAge(19);
	cout << "������� ��������:" << student.getAge() << endl;
	int marks[] = { 5,6,9,8,7,10,5,9 };
	student.setMarks(marks);
	cout << "������������ ������ � ��������:" << maxMark(student) << endl;//����� ������������� �������
}


//������ �3. ������������� ������������� ������� ��� ������� �������� ����� ������
class Woman {
private:
	string fullName;//���
	float weight;//���
	friend void setData(string, float, Woman&);
	friend void getData(Woman&);
public:
	Woman() {//�����������
		fullName = "�������� ���� ����������";
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
	cout << object.fullName << "\t: " << object.weight << " ��" <<
		endl;
}
void Woman::setData(string fullName, float weight) {
	this->fullName = fullName;
	this->weight = weight;
}
void Woman::getData() {
	cout << fullName << "\t: " << weight << " ��" << endl;
}
void Woman::showAdvice() {
	if (weight < 55) {
		cout << "��� ���� ���������� ������ ��������!" << endl;
		cout << "==================================" << endl;
	}
	else if (weight >= 55 && weight <= 65) {
		cout << "��� ��� � �����!" << endl;
		cout << "==================================" << endl;
	}
	else {
		cout << "��� ���� ������������ ���� � ���!" << endl;
		cout << "==================================" << endl;
	}
}
void Ex3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Woman woman1; //weight = 60, fullName = "�������� ���� ����������"
		woman1.getData();
	woman1.showAdvice();
	Woman woman2;
	woman2.setData("������� ���� ����������", 100);
	woman2.getData();
	woman2.showAdvice();
	Woman woman3; //������ ������
	setData("����� ���� ���������", 50, woman3);
	getData(woman3);
	woman3.showAdvice();
}


//������ �5. ���������� ������� ���������� ���������� � ���������� ��� friend - ������� ������
class Integer {
	int value;
public:
	Integer(int value) : value(value) {}
	//������� +
	friend const Integer& operator+(const Integer& obj);
	//������� -
	friend const Integer& operator-(const Integer& obj);
	//���������� ���������
	friend const Integer& operator++(Integer& obj);
	//����������� ���������
	friend const Integer operator++(Integer& obj, int);
	//���������� ���������
	friend const Integer& operator--(Integer& obj);
	//����������� ���������
	friend const Integer operator--(Integer& obj, int);
	friend ostream& operator<<(ostream& cout, Integer& obj) {
		cout << obj.value;
		return cout;
	}
};
//������� ���� ������ �� ��������, �� ���������� �������� ��������
const Integer& operator+(const Integer& obj) { return obj.value; }
//������� ����� �������� �������� ����� �������� �� ���������������
const Integer& operator-(const Integer& obj) {
	return Integer(-obj.value);
}
//���������� ������ ���������� ���������� �������� ����� �������������
const Integer& operator++(Integer& obj) {
	return Integer(++obj.value);
}
//����������� ������ ���������� ���������� �������� �� �������������
const Integer operator++(Integer& obj, int) {
	Integer oldValue(obj.value);
	obj.value++;
	return oldValue;
}
//���������� ������ ���������� ���������� �������� ����� �������������
const Integer& operator--(Integer& obj) {
	return Integer(--obj.value);
}
//����������� ������ ���������� �������� �� �������������
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
	cout << "���������� ������������� integer1:" << integer1 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = integer1++;
	cout << "����������� ������������� integer1:" << integer1 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = --integer2;
	cout << "���������� ������������� integer2:" << integer2 << endl;
	cout << "tempInteger:" << tempInteger << endl;
	tempInteger = integer2--;
	cout << "����������� ������������� integer2:" << integer2 << endl;
	cout << "tempInteger:" << tempInteger << endl;
}