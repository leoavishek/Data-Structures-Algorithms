/*This is a program to sort a bunch of elements in an array using Selection Sort 
Best Case:
Worst Case:
Average Case:
*/
#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>=arr[j]){
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
}

//Driver Code

int main(){
    printf("Enter the number of elements you want to enter :\n");
    int n;
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        printf("%d) ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\tBefore Swapping \n");
    for(int i=0;i<n;i++)
    printf("%d) %d\n",i+1,arr[i]);
    SelectionSort(arr,n);
    printf("\tAfter Swapping \n");
    for(int i=0;i<n;i++)
    printf("%d) %d\n",i+1,arr[i]);
    return 0;
}