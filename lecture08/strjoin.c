/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
    int size = 1;
    int i;
    char *dest;
    for (i=0; i<n; i++) {
        size = size + strlen(array[i]);
    }

    dest = (char *) malloc(size * sizeof(char));

    for (i=0; i<n; i++) {
        strcat(dest, tracks[i]);
        // printf("%s\n", array[i]);
        // printf("%i\n", k);
        // dest[k] = array[i];
        // printf("%s\n", dest);
        // k = k + strlen(array[i]);
    }
    dest[size-1] = '\0';

    // TODO: fill this in
    return dest;
}

int main (int argc, char *argv[])
{
    char *s = strjoin(tracks, 5);
    printf("\n%s\n\n", s);
    return 0;
}
