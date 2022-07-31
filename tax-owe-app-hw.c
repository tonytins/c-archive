#include <stdio.h>

// This application is purely for study purposes.

int main(int argc, char **argv)
{
	char name[100];

	printf("Tell me your name.\n");
	scanf("%s", name);
	printf("Welcome, %s!\n", name);

	return 0;
}
