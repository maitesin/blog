#include "functions.h"
#include "unity.h"

void test_two_plus_two(void)
{
	TEST_ASSERT_EQUAL_INT(4, sum(2, 2));
}

void test_minus_two_plus_two(void)
{
	TEST_ASSERT_EQUAL_INT(0, sum(-2, 2));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_two_plus_two);
	RUN_TEST(test_minus_two_plus_two);
	return UNITY_END();
}
