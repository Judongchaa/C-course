#include <stdio.h>

//!= ha una precenza maggiore rispesso a =

int main() {
    
    int c;

    int sq_counter, dq_counter;
    int prev_char = 0;

    int sl_comment = 0, ml_comment = 0;

    sq_counter = dq_counter = 0;

    FILE *source = fopen("1.1.c", "r");
    FILE *output = fopen("./1.1.nocomments.c", "w+");    

    while(((c = fgetc(source)) != EOF)) {
        if ((sl_comment == 0) && (ml_comment == 0)) {
            switch(c) {
                case '\'':
                   sq_counter++;
                   break;
                case '"':
                   dq_counter++;
                   break;
            }  

            if(c == '/' && prev_char == '/') {
                if (((sq_counter % 2) == 0) && (((dq_counter % 2) == 0))) {  
                    sl_comment = 1;
                } else {
                    fputc(c, output);
                }
            } else if (c == '*' && prev_char == '/') {
                 if (((sq_counter % 2) == 0) && (((dq_counter % 2) == 0))) {  
                    ml_comment = 1;
                } else {
                    fputc(c, output);
                }
            } else if (c == '/') {
                continue;
            } else if (prev_char == '/') {
                fputc(prev_char, output);
                fputc(c, output);
            } else {
                fputc(c, output);
            }           

       } else {
            if (c == '/' && prev_char == '*')
                ml_comment = 0;
            if (c == '\n') 
                sl_comment = 0;
        }
        prev_char = c;
    }


    fclose(source);
    fclose(output);

}
