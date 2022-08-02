/*Quicksort is a sorting algorithm which uses the divide and conquer algorithm
Best Case Scenerio    :nlogn
Worst Case Scenerio   :nlogn
Average Case Scenerio :n^2
Space Complexity      :logn
Stablity              :Typically no,but can be made using extra space or extra logic.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int partition(int *arr,int low,int high){//partition is done here
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[++i]<pivot)
            ;
        while(arr[--j]>pivot)
            ;
        if(i<j)//Swapping is done of the elements smaller and bigger then pivot
            swap((arr+i),(arr+j));
    }
    swap((arr+low),(arr+j));//Swapping of the pivot to its original place
    return j;
}
int Quicksort(int *arr,int low,int high){
    if(low<high){
        int j=partition(arr,low,high);
        Quicksort(arr,low,j);
        Quicksort(arr,j+1,high);
    }
}
int main(){
    printf("Enter the number of element you wnat to enter : ");
    int n;
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*(n+1));
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    arr[n]=INT_MAX;//Acts as the infinity.
    Quicksort(arr,0,n);
    printf("\t\tAfter Sorting : \n");
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}