#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "both.h"
#include "modulo.h"
#include "fff.h"
DEFINE_FFF_GLOBALS
#define TEST_F(SUITE, NAME) void NAME()
#define RUN_TEST(SUITE, TESTNAME) printf(" Running %s.%s: \n", #SUITE, #TESTNAME); setup(); TESTNAME(); printf(" SUCCESS\n");

FAKE_VALUE_FUNC1(int, modulo, int);

void setup()
{
	RESET_FAKE(modulo);
}

TEST_F(ModuloTest, both_even_numbers)
{
	int a;
	int b;
	int result;

	// Given
	a = 2;
	b = 4;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 0;
	modulo_fake.return_val_seq[1] = 0;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 0);
}

TEST_F(ModuloTest, first_even_and_second_odd)
{
	int a;
	int b;
	int result;

	// Given
	a = 2;
	b = 3;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 0;
	modulo_fake.return_val_seq[1] = 1;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 1);
}

TEST_F(ModuloTest, first_odd_and_second_even)
{
	int a;
	int b;
	int result;

	// Given
	a = 3;
	b = 2;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 1;
	modulo_fake.return_val_seq[1] = 0;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 1);
}


TEST_F(ModuloTest, both_odd_numbers)
{
	int a;
	int b;
	int result;

	// Given
	a = 3;
	b = 5;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 1;
	modulo_fake.return_val_seq[1] = 1;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 1);
}

TEST_F(ModuloTest, one_even_and_other_zero)
{
	int a;
	int b;
	int result;

	// Given
	a = 2;
	b = 0;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 0;
	modulo_fake.return_val_seq[1] = 0;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 0);
}

TEST_F(ModuloTest, one_odd_and_other_zero)
{
	int a;
	int b;
	int result;

	// Given
	a = 0;
	b = 5;
	modulo_fake.return_val_seq_len = 2;
	modulo_fake.return_val_seq = (int *) malloc(2*sizeof(int));
	modulo_fake.return_val_seq[0] = 0;
	modulo_fake.return_val_seq[1] = 1;

	// When
	result = both_even(a, b);

	// Then
	assert(result != 1);
}

int main(void)
{
	RUN_TEST(ModuloTest, both_odd_numbers);
	RUN_TEST(ModuloTest, both_even_numbers);
	RUN_TEST(ModuloTest, first_even_and_second_odd);
	RUN_TEST(ModuloTest, first_odd_and_second_even);
	RUN_TEST(ModuloTest, one_odd_and_other_zero);
	RUN_TEST(ModuloTest, one_even_and_other_zero);

	return 0;
}
