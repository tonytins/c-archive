#include <stdio.h>
#include <stdlib.h>

int main( void )
{

	FILE *source;

	source = fopen("printself.c", "r");

	long file_size;

	fseek(source, 0, SEEK_END);

	file_size = ftell(source);

	rewind(source);

	char *filedata;

	filedata = (char*) malloc(sizeof(char) * file_size);

	fread(filedata, 1, file_size, source);

	fclose(source);

	printf("%s\n", filedata);

	free(filedata);

	getchar();

	return 0;
}
