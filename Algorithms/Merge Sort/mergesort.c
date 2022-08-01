#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

void merge(int A[],int p,int q,int r){
    int n1 = q - p; //differs from book because C indexes from 0
    int n2 = r - q;
    int L[n1 + 1]; // L contains the first elem of A, up to the midpoint (not including the midpoint)
    int R[n2 + 1]; // R contains the elems including the midpoint of A all the way to the end.
    L[n1] = INT_MAX; //INT_MAX is our sentinel, which will be used in the merge step. No possible int will be greater than INT_MAX, so during the merge,
    R[n2] = INT_MAX; // INT_MAX is similar to the infinity used in the book
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[q + i];
    // Now we just need to merge L and R and sort A
    // The sorting occurs here, during the merge.
    int i = 0;
    int j = 0;
    for (int k = p; k < r; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void merge_sort(int A[],int p,int r) { // input is array A, first elem p, and last elem + 1 r

    if (p < r - 1) { //differs from book... since C indexes from 0, if we have an array of size 1, we will subtract 1 to get 0 and then hit the base case
                     // Otherwise, find the midpoint and divide and conquer
       int q = (p + r) / 2; //q is the midpoint of A
        merge_sort(A, p, q); //this must process the midpoint
        merge_sort(A, q, r); //this must process the elem after the midpoint to the last elem
        merge(A, p, q, r);
        return;
    }
}
int main(){
    int n,*arr;
    printf("Enter the elements you want to enter: \n");
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Original order of elems in A: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    merge_sort(arr,0,n);
    printf("\n\n");
    printf("after performing merge_sort: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
return 0;
}