#include <stdio.h>

#define IN 1
#define OUT 0

/* count digits, white space, others */
int main() {
	int c, i, char_per_word;
	int nwords[10];

	int state = OUT;

	char_per_word = 0;
	for (i = 0; i < 10; ++i)
		nwords[i] = 0;
	
	i = 0;

	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				nwords[i] = char_per_word;
				char_per_word = 0;
				i++;
			}			
		} else {
			state = IN;
			char_per_word++;
		}
		
		printf("Histogram: \n");
		for (int j = 0; j < i; j++) {
			printf("%d:", j);
			while (nwords[j]) {
				printf("*");
				nwords[j]--;
			}
			printf("\n");
		}
}
