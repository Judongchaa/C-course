#include <stdio.h>

int main() {
	int char_counter = 0;
	int blank_counter = 0;
	int c;

	char phrase[] = {};

	while ((c = getchar()) != 10) {
		if (c != 32) {
			phrase[char_counter] = c;
			char_counter++;	
		} else {
			phrase[char_counter];
		}
	}
	for(int i; i<char_counter; i++) { 
		printf("%c", phrase[i]);
		}
}
