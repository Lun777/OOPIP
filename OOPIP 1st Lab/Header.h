#pragma once

#include <iostream>
#include "Header.h"
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex6();
void Ex7();
void Ex8();
void Ex9();

int Program();

class Array {
	float* p_arr;
	int size;
public:
	Array() {
		cout << "\nВведите размер массива" << endl;
		cin >> size;
		while (!cin || (getchar() != '\n') || size < 1) {
			cout << "Нужно ввести целое число больше нуля! Повторите ввод:" << endl;
			cin.clear();
			rewind(stdin);
			cin >> size;
		}
		p_arr = new float[size];
	}
	Array(int size) {
		this->size = size;
		this->p_arr = new float[this->size];
	}
	~Array() {
		delete[] p_arr;
	}
	Array(const Array& other) {
		size = other.size;
		p_arr = new float[size];
		for (int i = 0; i < size; i++) {
			p_arr[i] = other.p_arr[i];
		}
	}
	void setValues();
	void displayArray();
	void crossArray(Array arr1, Array arr2);
	void concatArray(Array arr1, Array arr2);
	void WriteInFile();
};

void DeleteConsole();