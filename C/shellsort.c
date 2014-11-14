#include <stdio.h>
#include <stdlib.h>

void shellSort(int v[], int n) { //n is the len of the string
    int gap, i, j;
    for(gap=n/2; gap> 0; gap /= 2) { //start with n/2, then n/4, n/8… till 1;
      for(i=gap; i<n;  i++) { // step along elements
         for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
            int temp=v[j];
            v[j]=v[j+gap];
            v[j+gap] = temp;
        }
      }
  }
}

void printArray(int a[], int n) {
   int i;
   printf("\n");
   for (i=0; i<n; i++) {
    printf("%d, ", a[i]);
   }
   return ;
}

int main(void){

    int a[13] = { 11, 13, 5, 88, 4, 25, 91,28, 3, 22, 7, 32, 15 };
    int b[10] = { 11, 13, 5, 88,  28, 3, 22, 7, 32,15};
    int c[8] = { 11, 13, 5,  28, 3, 29, 17, 15};
    int d[17] = { 11, 13, 5, 88, 4, 25, 91,28, 3, 22, 7, 32, 15, 121, 44, 80, 69};

    shellSort(a, 13);
    shellSort(b, 10);
    shellSort(c, 8);
    shellSort(d, 17);
    printArray(a,13);
    printArray(b,10);
    printArray(c,8);
    printArray(d,17);
    return 0;
}
