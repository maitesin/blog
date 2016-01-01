#include<string.h>

char * strcpy(char * s1, const char * s2)
{
	strncpy(s1, s2, strnlen(s1, 512));
	return s1;
}
