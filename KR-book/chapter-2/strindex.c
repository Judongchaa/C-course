#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(void)
{
  char s[] = "Hello world or hello orbassano\n";
  char t[] = "o";

  int pos = strindex(s, t);
  printf("%d\n", pos);

  return 0;
}

int strindex(char s[], char t[])
{
  int rightmost = -1;
  int matching = 0;

  int slen = strlen(s);
  int tlen = strlen(t);

  for(int i = 0, j = 0; i<slen; i++)
  {
    if (s[i] == t[j]) {
        matching++;
        j++;
    } else {
        matching = 0;
        j = 0;
    }
    if (matching == tlen)
    {
        rightmost = (i-tlen+1);
        matching = 0;
        j = 0;
    }
  }
  return rightmost;
}
