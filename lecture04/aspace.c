/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void foo () {
	int local2 = 2;
	printf("Address of local2 is %p\n", &local2);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *m = malloc(20);
    void *n = malloc(20);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    foo();
    printf ("Address of p is %p\n", p);
    printf ("Address of m is %p\n", m);
    printf ("Address of n is %p\n", n);

    return 0;
}
