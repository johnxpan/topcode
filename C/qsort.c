/********************************************************************************
 * quick sort 
 * 1. select the mid element to be the pivot, swap it with leftest element
 * 2. set low to be left+1, high = right, 
 * 3. start from left, find first element  > pivot value, start from end,  find first element backward < pivot value
 * 4. swap two value and continue till left> right
 * 5. recursively call the qsort base on split array
 * ******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j) {
     int temp = v[i];
     v[i] = v[j];
     v[j] = temp;
}

void qsort(int v[], int left, int right) {
     int pivot;
     int lo, hi;

     if(left>= right)  // if array contain fewer than two elements, do nothing 
          return;
     swap(v, left, (left+right)/2); // select the mid item as pivot
     pivot = left;
     lo = left+1, hi=right;
     while(lo<=hi) {
          while(v[hi] > v[pivot])
             hi--;
          while (v[lo]<=v[pivot]) 
             lo++;
          if(lo <= hi) {
             swap(v, lo, hi);
             lo++, hi--;
          }     
     } 
     swap(v, left, hi);

     qsort(v, left, hi -1);
     qsort(v, hi +1, right);
}   


void printArray(int a[], int n)
{
    int i=0;
    for(i=0; i< n; i++) {
       printf("%d, ", a[i]);
    }
}

int main(void) {
  int v[10] = {11, 4, 8, 13, 57, 6, 18, 19, 22, 1};
  qsort (v, 0, 9);
  printArray(v, 9);
  return 0;
}
~                                                                                                                  
~             
