#include <stdio.h>
#define LETTER 0
int main ()
{
  char str[20]="C Language",c;
  int i=0;
  while((c=str[i])!='\0')
  {#if LETTER
     if(c>='a' && c<='z')
        c=c-32;
   #else
     if(c>='A' && c<='Z')
        c=c+32;
   #endif
   printf("%c",c);
   i++;
  }
  printf("\n");
  return 0; 
}
