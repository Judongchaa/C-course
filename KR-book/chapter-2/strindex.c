#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(void)
{
  char s[] = "Hello world or hello bassano\n";
  char t[] = "or";

  int pos = strindex(s, t); 
  printf("%d\n", pos);

  return 0;
} 

int strindex(char s[], char t[])
{
  int rightmost = -1;
  int slen = strlen(s);
  int tlen = strlen(t);

  for(int i = 0; i<slen; i++)
  {
    if(s[i] == t[0]) {
      int matching = 1;

      for (int j = 1; j<tlen; j++) 
      {
        i++;
        matching++;
        if (matching == tlen) rightmost = (i-tlen);
      }
    }
 
  }
  return rightmost;
}
