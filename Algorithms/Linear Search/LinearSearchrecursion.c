/*Linear Search is a premitive searching algorithm.It does not require pre_sorting the data/array.
Time Complexity  :O(n)
Space Complexity :O(1)
*/
#include<stdio.h>
#include <stdlib.h>
int LinearSearch(int *arr,int key,int n,int i){//The function actually does not return any value
    if(i==n ){
        printf("\t \t Element not found!!\n");
        return 0;
    }
    if(arr[i]==key){//To stop unnecessary recursion and break the recursion,I have used the return.
        printf("\t \t Element Found at position:%d!!\n",i+1);
        return 0;
    }
    LinearSearch(arr,key,n,i+1);
}
int main(){
    printf("Enter the number of elements you want to enter: ");
    int n,i,key;
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element you want to search : ");
    scanf("%d",&key);
    int a=LinearSearch(arr,key,n,0);
    return 0;
}