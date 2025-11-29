#include <stdio.h>
#include <string.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
    char s[] = "1234";
    double out = atof(s);

    printf("%f\n", out);

    return 0;
}

double atof(char s[])
{
    double exp, out;
    int sign, expsign, i;
    int expvalue = 0;

    int slen = strlen(s);

    for(i=0; isblank(s[i]); i++) {}

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;

    for(out = 0.0; isdigit(s[i]) && i<slen; i++) {
        out = out*10 + (s[i]-'0');
    }

    if(s[i]=='.' && i<slen) i++;

    for(exp = 1.0; isdigit(s[i]) && i<slen; i++) {
        out = out*10 + (s[i]-'0');
        exp *= 10;
    }

    if((s[i] == 'e' || s[i] == 'E') && i<slen) {
        i++;
        if (s[i] == '-') {
            expsign = -1;
            i++;
        } else if (s[i] == '+') {
            expsign = 1;
            i++;
        } else {
            expsign = 1;
        }
    }

    for(expvalue = 0.0; isdigit(s[i]) && i<slen; i++) {
        expvalue = expvalue*10 + (s[i]-'0');
    }

    out = out*sign/exp;
    expvalue *= expsign;

    if (expvalue > 0) {
        for(int i = 0; i<expvalue; i++) {
            out *= 10;
        }
    } else {
        for(int i = 0; i>expvalue; i--) {
            out /= 10;
        }
    }


    return out;
}
