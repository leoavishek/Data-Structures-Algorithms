/*Linear Search is a premitive searching algorithm.It does not require pre_sorting the data/array.
Time Complexity  :O(n)
Space Complexity :O(1)
*/
#include<stdio.h>
#include<stdlib.h>
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
    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("\t\tElement Found!!! at position: %d\n",i);
            break;//Used to break out of the loop to stop unnecessary iteration
        }
    }
    if(i==n)//i will only be equal to n when the iteration has not found the element
        printf("\t \tElement Not Found\n");
    return 0;
}