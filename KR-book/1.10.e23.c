#include <stdio.h>

int main() {

    int c, sq_counter, dq_counter;
    int prev_char = 0;

    int sl_comment = 0, ml_comment = 0;

    sq_counter = dq_counter = 0;

    FILE *source = fopen("1.1.c", "r");
    FILE *output = fopen("./1.1.nocomments.c", "w+");    

    while(((c = fgetc(source)) != EOF)) {
        
        if (sl_comment == 0 && ml_comment == 0) {
            
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

            if (((sq_counter % 2) != 0) || ((dq_counter % 2) != 0)) { //passata questa condizione sono sicuro di non trovarmi in una stringa
                fputc(c, output);
            } else if(c == '/') {
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
        } else {
            if (c == '\n' && sl_comment == 1) {
                fputc(c, output);
                sl_comment = 0;
            } else if (c == '/' && prev_char == '*') {
                ml_comment = 0;
            }
        }
        prev_char = c;
    }
    fclose(source);
    fclose(output);
}
