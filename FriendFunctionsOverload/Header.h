#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

#define N 5

using namespace std;

void WriteInFile(char* str);

class String {
private:
	char* str;
	int length;
public:
	String(const String& string) {
		length = string.length + 1;
		str = new char[length];
		strcpy_s(str, length, string.str);
	}
	String(char* beg) {
		length = strlen(beg) + 1;
		str = new char[length];
		strcpy_s(str, length, beg);
		WriteInFile(str);
	}
	String() {
		str = NULL;
		length = 0;
	}
	~String() {
		delete[] str;
	}
	void SetString();
	void SetString1(char* s);
	const char* GetString() const {
		return str;
	};
	void DisplayString();
	friend void WriteInFile(char* str);
	friend ostream& operator<<(ostream& cout, const String& s) {
		cout << s.str;
		return cout;
	}
	friend istream& operator>>(istream& cin, String& s) {
		char str[100];
		cin >> str;
		s.SetString1(str);
		return cin;
	}
	bool operator!();
	void operator[](int pos);
	void operator()(int pos, int length);
};

void DeleteConsole();

void Program();

void Ex1();

void Ex3();

void Ex5();