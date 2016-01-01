#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Bad number of parameters.\nUsage: %s <string up to 512 characters>\n", argv[0]);
		return 1;
	}
	char s[512];
	strcpy(s, argv[1]);
	printf("You introduced: %s\n", s);
	return 0;
}
