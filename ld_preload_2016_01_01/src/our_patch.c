#include<string.h>

char * strcpy(char * s1, const char * s2)
{
	strncpy(s1, s2, strlen(s1));
	return s1;
}
