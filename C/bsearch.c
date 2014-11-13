//implement binary search
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int key, int v[], int len) {
   int low = 0; 
   int high = len -1 ;
   int mid;

   while (low <=  high) {
      mid = (low + high)/2;
      if( key < v[mid]) {
          high = mid-1;
      } else if (key > v[mid]) {
          low = mid+1;
      } else {
          return mid;
      }
   }
   return -1;
}
        
//recursive method
int binary_search(int key, int a[], int low, int high) {
    if (high < low) // base case
        return -1;
    int mid = (low + high)/2;
    if (key < a[mid])
        return binary_search(key, a, low, mid-1);
    else if (key > a[mid])
        return binary_search(key, a, mid+1, high);
    else if (key == a[mid])
        return mid;
}
   
int main(void) {
   int i;
   int v[] = {7, 9, 13, 15, 18, 23, 25, 27};

   i = binary_search (13, v, 0, 7);
   printf("\n%s\n", (i>=0)?"found":"no");
   i = binary_search (33, v, 0, 7); 
   printf("\n%s\n", (i>=0)?"found":"no");
   return 0;
}
