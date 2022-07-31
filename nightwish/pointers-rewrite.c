/* 

	Here, i will attempt to show you some simple concepts of 'pointers'
	Including a few common uses, as well as the differences
	between a dereference and a  reference pass...

*/

/* standard include file for IO.... */

#include <stdio.h>
#include <stdlib.h>


/* Main function */

int main ( int argc, char * argv[] )

/*
	The above is a stack pointer, it's placed on the current
	execution space of the program (the memory is allocated at startup).
	There's no heap used here and thus we don't 'free' any memory.
	argv[] is a string constant,
	it's the command line passed to the program
	on startup. Where [0] is the actual executable name
*/

{

	/* Now, let's make a pointer! */

	char *FirstPointer; /* This is a 'stack pointer' */

/*

	Remember that the above IS a pointer, but it's an stack-space
	one. Meaning it's allocated at startup.

	The stack can only be a certian size, if all the data 
	won't fit on it, it may get cut off or give
	undefined behaviour. So let's convert our 'stack' to a
	'heap pointer below
*/

	FirstPointer = (char *) malloc(sizeof(char) * 200000);

/*
	OK! Now we have a nice, BIG space in the 'heap' (the rest of the 
	system's RAM that's not beeing used by a program). We'll just
	work with data under 200000 bytes long for now so as not to cause
	a memory leak. So, what shal we -do- with our baby? Hmm, i have
	an idea.....
*/

	*FirstPointer = (char *)"Hello There, i belong on the heap!\n";

/*	Let's make it say something for us!
	The trick here is the asterisk (*) will 'dereference' the pointer.
	When we dereference a pointer, we no longer worry about the
	memory address, we worry about, and work with the DATA!
	If we work by REFERENCE we are working with the ADDRESS!
	The &-sign is the reference operator, we'll work with that soon.
*/

	/* Let's put something on screen... */

	printf("%s", FirstPointer);

/*	Ok, we have text-on-screen action! Sexy! Now, let's make another
	pointer, here's where reference play comes in!
*/

	char *SecondPointer; /* Another char (byte) pointer, to match types with the first one. */

/*	Now let's see what happens if we do the following.... */

	SecondPointer = (char *)&FirstPointer;

/*	We passed the ADDRESS of the 'FirstPointer' (our heap pointer)
	to our second, which can accept the address, let's print the
	second one to the screen!
*/

	printf("%s", SecondPointer);

/*	Sweet, more screen action! Now let's do something a bit odd....
*/

	char *ThirdPointer; /* Wow this crap is becomming common.... */

	ThirdPointer = (char *) *SecondPointer;

/* 	Hmm, interesting... We have just copied the data from the FIRST
	pointer to the third! But how???

	It's simple, when we did the address assign (&FirstPointer)
	earlier in the code, it placed the address in SecondPointer.
	That links SecondPointer and FirstPointer together! They can share
	data now. ThirdPointer now equals the data of second pointer, 
	which by address points to first pointer, so we have a circle.

	Let's see it in action.....
*/

	printf("%s", ThirdPointer);

/*	Yay, more output, But what happens if we do something like this?
*/

	printf("%s  %s   %s", &FirstPointer, &SecondPointer, &ThirdPointer);

/*	Well, what'cha know? We have the addresses on screen of all
	three pointers! Two of them (first and second) should be the same
	While third should be different.....

	Reason for third beeing different???

	We didn't assign it ANY Address, ONLY data!

	Ok, we have worked with our pointers and are all done....
	What do we do now? THat funny malloc() stuff did something
	right? Yes it did! It told the kernel of the OS to allocate
	some of the computer's RAM so we could put stuff in it.
	Now we need to be nice to the OS and our computer and
	give the RAM back with free(). Free() tells the kernel
	'We're done, you can have this back now'. If a program with an
	malloc() ends without a free() to release, you have a memory leak.

	A memory leak is when RAM is allocated and not freed once the 
	stack is destroyed (main returns and exits). The RAM is still
	there and possibly usable, but it hasn't been set back to 
	zero-byte yet. So to be nice let's free......
*/

	free(FirstPointer); /* Done, no mem leaks now! */

	/* And a nice return to let the kernel know we're all done */

	return 0;

}



