#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Error: Bad number of parameters\n");
		fprintf(stderr, "Usage: %s <how many times>", argv[0]);
		return -1;
	}

	int num = atoi(argv[1]);
	int input = 0;
	int acum = 0;
	for (int i = 0; i < num; ++i) {
		printf("Next one: ");
		scanf("%d", &input);
		acum += input;
	}

	printf("Total acumulated: %d\n", acum);
	return 0;
}
