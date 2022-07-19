/*This is a program to sort a bunch of elements in an array using Bubble Sort 
Best Case: O(n), if already sorted array is passed
Worst Case: O(n^2)
Average Case: O(n^2)
*/
#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int arr[],int n){
    for(int i=1;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i;j++){
            if(arr[j]>=arr[j+1]){//Swapping of the integers are done here
                arr[j]=arr[j]^arr[j+1];
                arr[j+1]=arr[j]^arr[j+1];
                arr[j]=arr[j]^arr[j+1];
                flag=1;
            }
        }
        if(flag==0)//This flag is used to shorten the iteration when the array is already sorted
            break;
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
    BubbleSort(arr,n);
    printf("\tAfter Swapping \n");
    for(int i=0;i<n;i++)
    printf("%d) %d\n",i+1,arr[i]);
    return 0;
}