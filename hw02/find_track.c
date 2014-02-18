/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5
#define MAX_MATCHES 1

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    puts("\nFind track search:\n");
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
    	if (strstr(tracks[i], search_for)) {
    	    printf("Track %i: '%s'\n", i, tracks[i]);
    	}
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(regex_t *search) 
{
    puts("\nRegex search:\n");
    regmatch_t matches[MAX_MATCHES]; //A list of the matches in the string (a list of 1)
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (regexec(search, tracks[i], MAX_MATCHES, matches, 0) == 0) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	   *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    find_track(search_for);

    int rv;
    regex_t exp;
    rv = regcomp(&exp, search_for, REG_EXTENDED);
    if (rv != 0) {
        printf("regcomp failed with %d\n", rv);
    }
    find_track_regex(&exp);
    regfree(&exp);
    return 0;
}

//user input regex string they want
//use regcompile on that
// call function which calls regexec with each track name
// regfree to close out at end
