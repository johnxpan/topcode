/**********************************************************************************
 * Merge Sort invented by John von Neummann in 1945, Two steps                    *
 * 1. Divide the unsorted list into n subarray, each containing 1 element (sorted)* 
 * 2. we need allocate a temp array to each merge of two subarray. we select the  *
 * lowest number from two subarray, and put them into temp array, till done       * 
 * 3. Repeatedly merge subarray to produce new sorted subarray until there is only*
 * one sub array remaining. This will be the sorted list.                         *
 * Average performance O(nlogn), Worst Case: O(nlogn)                             *
 *********************************************************************************/
#include<stdio.h>
#define MAX 50

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main(){

    int merge[MAX],i,n;

    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++){
         scanf("%d",&merge[i]);
    }

    partition(merge,0,n-1);

    printf("After merge sorting elements are: ");
    for(i=0;i<n;i++){
         printf("%d ",merge[i]);
    }

   return 0;
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

    l=low;  // start index to the first subarray: low-mid
    i=low;  // start index to the temp array 
    m=mid+1; // start index to the second subarray  mid+1-high

    // copy elements from 2 sub array to temp array
    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    //copy the rest of elements of rest  

    // one subarray must be done
    if(l<=mid) { //first subarray are not finished
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    } else {  // second half array are not done
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    // copy back elements from temp to main 
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

