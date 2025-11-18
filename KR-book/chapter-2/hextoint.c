#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char hex[]);
int isHex(char hex[]);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("%s to integer is: %d\n", argv[1], htoi(argv[1]));
        return 0;
    } else {
        printf("No valid arguments\n");
        return 0;
    }
   
    return 0;
}

int htoi(char hex[]) {
    if (!isHex(hex)) return 0;
    
    int len = strlen(hex);
    int pos = 0;
    int value = 0;

    for ( ; hex[len] != 'x'; len--) {
        if (hex[len] >= '0' && hex[len] <= '9') {
            value += (hex[len] - 48) * pow(16, pos);
            pos++;
        } else if (hex[len] >= 'A'  && hex[len] <= 'F'){
            value += (hex[len] - 55) * pow(16, pos);
            pos++;
        } else if (hex[len] >= 'a' && hex[len] <= 'f') {
            value += (hex[len] - 87) * pow(16, pos);
            pos++;
        }
    }


    return value;
}

int isHex (char hex[]) {
    if(hex[0] == '0' && hex[1] == 'x') {
        return 1;
    }
    return 0;
}
