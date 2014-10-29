#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverse3(char *s, char *e)
{
    if(s < e){
       char temp = *s;
       *s++ = *e;
       *e-- = temp;
       reverse3(s, e);
    } else {
      return;
    }
}


void reverse2(char *s)
{
   char *e=s;
   while(*e)
      e++;
   e--;
   while(s < e){
     char temp =*s;
     *s = *e;
     *e = temp;
     s++; e--;
   }
}

void reverse(char *s)
{
    int i = 0;
    int len = strlen(s);

    for(i=0; i< len/2; i++) {
        char temp;
        temp = s[i];
        s[i]= s[len-1-i];
        s[len-1-i] = temp;
     }
   }
}

int main(void) {
   char s[] = "I am here";
   char *str = s;
   char *end = s+ strlen(s)-1;
   printf("\n %s\n", s);
   //reverse2(s);

   reverse3(str, end);
   printf("\n reversed string %s\n", s);

   return 0;
}



