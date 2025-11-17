#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* lowercase(char input[])  {
    short len = strlen(input);
    char *s = malloc(len+1);

    if (s == NULL) return NULL;

    for(int i = 0; i<len; i++) {
        if(input[i] >= 65 && input[i] <=90) { 
            s[i] = input[i]+32;
        } else {
            s[i] = input[i];
        } 
    }
    s[len] = '\0';
    return s;
}


void any(char s1[], char s2[]) {
    short len = strlen(s1);
    short nchar = strlen(s2);
    int pos;
    
    for(int i=0; i<nchar; i++) {
       pos = -1;
       for (int j=0; j<len; j++) {
            if (s2[i] == s1[j]) {
                pos = j;
                break;
            }
       }
       printf("Char %c is located at index %d\n", s2[i], pos);
                
    }
}

int main(void) {

    char s1[] = "Hello World";
    char s2[] = "abcde";
    
    any(s1,s2);

    return 0;
}
