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

TEST(polynom_tests, sort_polynom_is_sorting) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.96, 3, 2, 0);
	monom m3(1.26, 3, 2, 1);

	Polynom P; P.addM(m1); P.addM(m2); P.addM(m3);
	P.SortDeg();
	Polynom P1; P1.addM(m2); P1.addM(m3); P1.addM(m1);
	EXPECT_EQ(P, P1);
}

TEST(polynom_tests, can_count_polynom) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.86, 3, 2, 0);

	Polynom P; P.addM(m1); P.addM(m2);;
	double res = 13.0;
	EXPECT_EQ(res, P.counter(1, 1, 1));
}

TEST(polynom_tests, operator_add_test) {
	monom m1(3.14, 1, 2, 3);
	monom m2(9.86, 3, 2, 3);
	monom m3(1.26, 3, 2, 1);

	Polynom P; P.addM(m1); P.addM(m2); P.SortDeg();
	Polynom P1; P1.addM(m2); P1.addM(m3); P1.SortDeg();
	Polynom R = P + P1;
	
	
	monom m22(19.72, 3, 2, 3);
	Polynom R1; R1.addM(m3); R1.addM(m1); R1.addM(m22);
	EXPECT_EQ(R, R1);
}

TEST(polynom_tests, operator_sub_test) {
	monom m1(3.14, 1, 2, 3);
	monom m2(0.0, 3, 2, 3);
	monom m3(-1.26, 3, 2, 1);

	Polynom P; P.addM(m1); P.SortDeg();
	Polynom P1; P1.addM(m3); P1.SortDeg();
	Polynom R(P - P1); //R.Print();

	monom m32(1.26, 3, 2, 1);
	Polynom R1; R1.addM(m32); R1.addM(m1);
	EXPECT_EQ(R, R1);
}

TEST(polynom_tests, operator_mul_test) {
	monom m1(3.14, 1, 2, 3);
	monom m2(0.0, 3, 2, 3);
	monom m3(1.0, 3, 2, 1);

	Polynom P; P.addM(m1); P.addM(m2); P.SortDeg();
	Polynom P1; P1.addM(m2); P1.addM(m3); P1.SortDeg();
	Polynom R = P * P1; R.SortDeg();

	monom m13(3.14, 4, 4, 4);
	Polynom R1; R1.addM(m13);
	EXPECT_EQ(R, R1);
}

TEST(polynom_tests, operator_mul_pol_on_const_test) {
	monom m1(3.14, 1, 2, 3);
	monom m3(1.0, 3, 2, 1);
	monom m11(-3.14, 1, 2, 3);
	monom m33(-1.0, 3, 2, 1);
	Polynom P; P.addM(m1); P.addM(m3); P.SortDeg();
	P = P*(-1.0);
	Polynom P1; P1.addM(m11); P1.addM(m33); P1.SortDeg();
	EXPECT_EQ(P, P1);
}

TEST(polynom_tests, pause) {
	bool t = true;
	system("pause");
	EXPECT_EQ(t, true);
}
