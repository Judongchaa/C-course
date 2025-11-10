#include <stdio.h>

#define IN 1
#define OUT 0
/* returns the maximum value in an array */
int max_in_array(int *nwords, int array_lenght) {
	int temp = 0;
	for (int i = 0; i<array_lenght; i++) {
		if (nwords[i] > temp) {
			temp = nwords[i];
		}
	}
	
	return temp;
}
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
			nwords[i] = char_per_word;

		}
		
	printf("\nHistogram: \n");
	
	while(max_in_array(nwords, 10)) {
		for (int j = 0; j <= i; j++) {
			if (nwords[j] > 0) {
				printf("* ");
				nwords[j]--;
			
			} else {
				printf("  ");
			}	
		}
		printf("\n");
	}
}

