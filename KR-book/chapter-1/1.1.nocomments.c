#include <stdio.h>

int main() {
    
    printf("Hello world!\n"); 
    printf("Non // è un commento dentro una stringa!\n");
    printf("E nemmeno /* questo */\n");
    char c = '/'; 
    char s[] = "Stringa con \\\"escape\\\" e // dentro";
    
    printf("Fine del programma\n");
    return 0;
}
