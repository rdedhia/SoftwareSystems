#include <stdio.h>
#include <stdlib.h>

void inputHandler(char *card, int *val) {
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
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		counter(&card_name, &count);
	}
	return 0;
}