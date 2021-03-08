#pragma once

#include <iostream>
using namespace std;

class roman {
	string value;
public: 
	roman(string _value = "") { value = _value; }
	friend bool operator == (const roman _r1, const roman _r2);
	void add(string _r) {
		value += _r;
	}
	char GetRom(int i) { return value[i]; }
	int GetLenRom() { return value.length(); }
};

struct arabic {
	int value;
public:
	arabic(int _value = 0) { value = _value; }
	friend bool operator == (const arabic _a1, const arabic _a2);
	void add(int _a) {
		value += _a;
	}
	int GetAr() { return value; }
};

// I V X  -  M C

class Convertor {
	roman rm;
	arabic ar;

public:
	Convertor(roman _rm, arabic _ar) { rm = _rm; ar = _ar; }

	friend arabic toArabic(roman t);
	friend roman toRoman(arabic t);

	void printRm();
	void printAr();

	void checkRoman(roman &t);        // IIII - IV							 // оператор ввода-вывода, либо print

};
