#include "RomanToArabic.h"

using namespace std;
int main() {

	arabic A;

	roman R("MV");

	A = toArabic(R); 

	Convertor C1(R, A);

	C1.printAr();

	//system("pause");
	return 0;
}