#include <stdio.h>
#include <stdlib.h>

int negate (int a) {
   int neg = 0;

   int d = (a<0)?1:-1;

   while (a!=0) {
     neg += d;
     a +=d;
   }
   return neg;
}

int main (void) {
  int a= 12;
  int b= -20;

  printf("-a = %d, -b= %d\n", negate(a), negate(b));
  return 0;
}
/*********************************/
