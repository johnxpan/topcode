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

void mqsort (int v[ ], int left, int right) {
  int i, pindex;
  void swap(int v[], int i, int j) ;

  if(left>=right)
      return;  // array contains less than 2 elements
  swap(v, left, (left+right)/2); // swap the pivot (mid element) with first element
  pindex= left;   // move partition element to v[0]
  for(i = left+1; i<=right; i++) {
        if(v[i] < v[left]) ;
           swap(v, ++pindex, i);
  }
  swap(v, left, pindex);  // restore partition element 
  mqsort (v, left, pindex-1);
  mqsort (v, pindex+1, right);
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
  mqsort (v, 0, 9);
  printArray(v, 9);
  return 0;
}
~                                                                                                                  
~             
