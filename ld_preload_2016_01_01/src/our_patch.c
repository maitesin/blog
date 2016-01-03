#include<string.h>

char * strcpy(char * s1, const char * s2)
{
	strncpy(s1, s2, 511);
	s1[511] = '\0';
	return s1;
}
