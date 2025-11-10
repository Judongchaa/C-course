#include <stdio.h>

int main() {
	int char_counter = 0;
    int prev_space = 0;
	int c;

	char phrase[100] = {0};

	while ((c = getchar()) != 10) {
		if (c != 32) {
            prev_space = 0;
			phrase[char_counter] = c;
            char_counter++;
		} else {
			phrase[char_counter] = c;
            if (!prev_space) char_counter++;
            prev_space = 1; 
                
        }
	}
	for(int i = 0; i<char_counter; i++) { 
		printf("%c", phrase[i]);	
    } 
    printf("\n");

}
