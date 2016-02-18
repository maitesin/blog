#include "both.h"
#include "modulo.h"

int both_even(int a, int b)
{
	int a_m, b_m;
	a_m = modulo(a);
	b_m = modulo(b);
	return a_m == 0 && b_m == 0;
}


