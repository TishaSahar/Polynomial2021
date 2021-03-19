#pragma once

#include <iostream>
using namespace std;

													// Класс моном
class monom{
	double a;
	long int deg;
	const int maxDegree = 29 * 10000 + 29 * 100 + 29;
public:
	monom(double _a = 1.0, int i = 1, int j = 1, int k = 1) {   //Конструктор монома
		a = _a;
		deg = i + 100 * j + 10000 * k;
		if (deg > maxDegree) throw logic_error("deg > 30");
	}
	double getA() { return a; }
	int getK() { int r = deg / 10000; return r; }
	int getJ() { int r = (deg - (getK() * 10000)) / 100;  return r; }
	int getI() { int r = deg % 100;  return r; }
	long int getDeg() { return deg; }

	void setA(double _a) { a = _a; }
	void setDegree(int _deg) { deg = _deg; }
	monom operator = (const monom &_m);
	friend ostream &operator << (ostream &out, const monom &m); 
	friend bool operator != (monom& l, monom& r);
};


										// Вспомогательный класс Node
class Node
{
public:
	monom value; 
	Node* next; 
	Node(monom _value, Node* _next = NULL) {
		value = _value;
		next = _next;
	}
};

												// Класс полином

class Polynom{
	Node *first;
	Node *tail;

public:
	int count;
	Polynom(Node *_first = NULL, Node *_tail = NULL) :first(_first), tail(_tail) { count = 0; }
	~Polynom() { first = NULL; }
	Polynom(const Polynom& _p);
	int getCount() { return count; }
	void addM(monom _m);
	void Print();
	void SortDeg();
	void Clear();
	monom Polynom::operator[](const int index);
	Polynom operator=(const Polynom& P);
	const Polynom operator+(const Polynom& RV)const;
	const Polynom operator-(const Polynom& RV)const;
	const Polynom operator*(const Polynom& RV)const;
	friend bool operator == (const Polynom& l, const Polynom& r);
	double counter(double x, double y, double z);
};

