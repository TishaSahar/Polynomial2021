#include <gtest.h>
#include "RomanToArabic.h"

TEST(test_convertor_to_arabic, test_one)
{
	roman R("I");
	arabic v = toArabic(R);
	arabic v1(1);
	EXPECT_EQ(v1, v);
}

TEST(test_convertor_to_arabic, test_five)
{
	roman R("V");
	arabic v = toArabic(R);
	arabic v1(5);
	EXPECT_EQ(v1, v);
}

TEST(test_convertor_to_arabic, test_2940)
{
	roman R("MMCMXL");
	arabic v = toArabic(R);
	arabic v1(2940);
	EXPECT_EQ(v1, v);
}

TEST(test_convertor_to_arabic, test_12)
{
	roman R("XII");
	arabic v = toArabic(R);
	arabic v1(12);
	EXPECT_EQ(v1, v);
}






TEST(test_convertor_to_roman, test_one)
{
	arabic A(1);
	roman r = toRoman(A);
	roman r1("I");
	EXPECT_EQ(r, r1);
}

TEST(test_convertor_to_roman, test_4)
{
	arabic A(4);
	roman r = toRoman(A);
	roman r1("IV");

	EXPECT_EQ(r, r1);
}

TEST(test_convertor_to_roman, test_2941)
{
	arabic A(2941);
	roman r = toRoman(A);
	roman r1("MMCMXLI");
	EXPECT_EQ(r, r1);
}