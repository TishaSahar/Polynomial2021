#include "Polynomial.h"

using namespace std;
int main() {

	monom m1(3.14, 1, 1, 1);
	monom m2(9.96, 3, 2, 0);
	monom m3(9.96, 2, 2, 2);

	Polynom P; P.addM(m2); P.addM(m1); P.addM(m3); P.addM(m2);
	Polynom P1; P1.addM(m3); P1.addM(m1); P1.addM(m1); P1.addM(m3);

	P.SortDeg(); P1.SortDeg();
	P.Print(); P1.Print();
	Polynom P2(P1 - P);
	P2.Print();

	return 0;
}