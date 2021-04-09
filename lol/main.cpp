//Copyright by Dunyushkina Ekaterina 19BI-2
#include "BinCalc.h"
#include <iostream>

using namespace std;

int read() {
	int value;
	cin >> value;
	if (value == 0) throw "Division by zero!";
	return value;
}

int readZ() {
	char znak2;
	cin >> znak2;
	if (!(znak2 == '+' || znak2 == '-' || znak2 == '*')) throw "Incorrect Input!";
	else if (znak2 == '+') return 0;
	else if (znak2 == '-') return 1;
	else return 2;
}

int main() {
	int a, b, znak, a1, b1;
	try {
		a1 = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	try {
		a = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}

	try {
		znak = readZ();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	try {
		b = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	BinCalc left(a, a1), right(b, a1);
	if (znak == 0) {
		cout << left << endl << right << endl;
		cout << left + right;
	}
	else if (znak == 1) {
		cout << left << endl << right << endl;
		cout << left - right;
	}
	else {
		cout << left << endl << right << endl;
		cout << left * right;
	}
}