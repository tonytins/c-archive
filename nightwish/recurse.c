#include <stdio.h>

void Recurse( int number )
{

	printf("Call #: %d\n", number);
	Recurse(number+1);
}

int main( void )
{

	Recurse(1);

	return 0;
}
