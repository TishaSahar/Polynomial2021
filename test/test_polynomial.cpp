#include <gtest.h>
#include "Polynomial.h"

TEST(monom_tests, can_create_monom) {
	ASSERT_NO_THROW(monom m(3.14, 1, 2, 3));
}

TEST(monom_tests, can_copy_monom) {
	monom m(3.14, 1, 2, 3);
	ASSERT_NO_THROW(monom m1 = m);
}

TEST(polynom_tests, can_create_polynom) {
	ASSERT_NO_THROW(Polynom P);
}

TEST(polynom_tests, can_copy_polynom) {
	monom m(3.14, 1, 2, 3);
	Polynom P;
	P.addM(m);
	ASSERT_NO_THROW(Polynom P1(P));
}

TEST(polynom_tests, can_add_new_monom_to_polynom) {
	monom m(3.14, 1, 2, 3);
	Polynom P;

	ASSERT_NO_FATAL_FAILURE(P.addM(m));
}


TEST(polynom_tests, can_print_polynom) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.96, 3, 2, 0);

	Polynom P; P.addM(m1); P.addM(m2); P.addM(m1);
	ASSERT_NO_THROW(P.Print());
}

TEST(polynom_tests, can_sort_monoms_in_polynom) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.96, 3, 2, 0);

	Polynom P; P.addM(m1); P.addM(m2); P.addM(m1);
	ASSERT_NO_THROW(P.SortDeg());
}

/*TEST(polynom_tests, sort_polynom_is_sorting) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.96, 3, 2, 0);
	monom m3(1.26, 3, 2, 1);

	Polynom P; P.addM(m1); P.addM(m2); P.addM(m1); P.addM(m3);
	P.SortDeg();
}*/

TEST(polynom_tests, can_count_polynom) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.86, 3, 2, 0);

	Polynom P; P.addM(m1); P.addM(m2);;
	double res = 13.0;
	EXPECT_EQ(res, P.counter(1, 1, 1));
}
