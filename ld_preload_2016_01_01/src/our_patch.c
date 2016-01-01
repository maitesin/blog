#include<string.h>

char * strcpy(char * s1, const char * s2)
{
	return strncpy(s1, s2, strnlen(s2, 512));
}
