/*Modified code from card_counter.c in Head First C 
by Griffiths and Griffiths

Code is now split into three functions

Modified by Rahil Dedhia
Software Systems Homework 01*/

#include <stdio.h>
#include <stdlib.h>

void inputHandler(char *card, int *val) {
	/* Takes the user input card and calculates its value
	if it is a valid input. Otherwise, gives an
	error message to the user */
	switch(*card) {
	case 'K':
	case 'Q':
	case 'J':
		*val = 10;
		break;
	case 'A':
		*val = 11;
		break;
	case 'X':
		break;
	default:
		*val = atoi(card);
		if ((*val < 1) || (*val > 10)) {
			puts("I don't understand that value!");
			break;
		}
	}
}

void counter(char *card, int *count) {
	/* Takes card value from the inputHandler function, 
	increments or decrements the count accordingly, and
	then prints the count.
	*/
	int val = 0;
	inputHandler(card, &val);
	if ((val > 2) && (val < 7)) {
		*count = *count + 1;
	} else if (val == 10) {
		*count = *count - 1;
	}
	printf("Current count: %i\n", *count);
}

int main() {
	/* Main function - contains while loop which prompts
	user for a card name until the user submits 'X'. User input
	must be limited to 2 characters. Then calls the counter
	function to increment or decrement the count depending
	on the card value.
	*/
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		counter(&card_name, &count);
	}
	return 0;
}