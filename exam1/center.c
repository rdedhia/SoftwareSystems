/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    char *dest;
    int total = 1;
    int i; int j;
    total = total + n + strlen(s);
    //printf("%i\n", total);
    dest = (char *) malloc (total * sizeof(char));
    
    int half = n/2;
    for (i=0; i<half; i++) {
        dest[i] = fillchar;
    }
    strcat(dest, s);
    for (j=strlen(s)+half; j<total-1; j++) {
        dest[j] = fillchar;
    }
    return dest;
}

int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
