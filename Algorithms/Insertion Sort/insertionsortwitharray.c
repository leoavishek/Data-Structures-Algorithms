/*
This is the code of insertion sort(Ascending order) done in C
Best Case scenerio O(n)
Worst Case Scenerio O(n^2)
Average Case Scenerio O(n^2)
Even though the average case and the worst case scenerio is same as Bubble Sort or Selection Sort,the number of
shifts are lower so practically this is a better algorithm.
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter the number of elements you want to enter :\n");
    int  n;
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("Enter the Elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n \t\tBefore sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d) %d\n",i,arr[i]);
    }
    for(int i=1;i<n;i++){
        int value=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
    printf("\n \t\tAfter sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d) %d\n",i,arr[i]);
    }
    return 0;
}
