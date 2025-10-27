#include <stdio.h>

int main() {

    int c, sq_counter, dq_counter;
    int prev_char = 0;

    int sl_comment = 0, ml_comment = 0;

    sq_counter = dq_counter = 0;

    FILE *source = fopen("1.1.c", "r");
    FILE *output = fopen("./1.1.nocomments.c", "w+");    

    while(((c = fgetc(source)) != EOF)) {
        
        if (sl_comment == 1) {
            if (c == '\n') {
                sl_comment = 0;
                continue;
            }
        }
        
        if (ml_comment == 1) {
            if (c == '/' && prev_char == '*') {
                ml_comment = 0;
                continue;
            } else if (c == '\n') {
                fputc(c, output);
            }
        } 
        
        switch(c) {
          case '\'':
              if(prev_char != '\\')  
                    sq_counter++;
              break;
          case '"':
              if(prev_char != '\\')
                    dq_counter++;
              break;
        }

        // se mi trovo in una stringa incollo il carattere e ricomincio il ciclo
        if (((sq_counter % 2) != 0) || ((dq_counter % 2) != 0)) { 
            fputc(c, output);
            continue;
        }

        if(c == '/') {
            int next = fgetc(source);
            if (next == '/') { 
                sl_comment = 1;
            } else if (next == '*') {
                ml_comment = 1;
            } else {
                fputc(c, output);
                fputc(next, output);
            }
        } else {
            fputc(c, output);
        }
       prev_char = c;
    }
    fclose(source);
    fclose(output);
}
