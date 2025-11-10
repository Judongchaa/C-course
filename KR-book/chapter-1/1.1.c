#include <stdio.h>

int main() {
    // Questo è un commento singolo
    printf("Hello world!\n"); /* E questo è un commento multilinea */
    printf("Non // è un commento dentro una stringa!\n");
    printf("E nemmeno /* questo */\n");
    char c = '/'; // questo è uno slash normale
    char s[] = "Stringa con \\\"escape\\\" e // dentro";
    /*
     * Commento
     * su
     * più righe
     */
    printf("Fine del programma\n");
    return 0;
}
