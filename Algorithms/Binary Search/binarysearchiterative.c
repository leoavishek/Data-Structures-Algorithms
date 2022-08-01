#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int key,int *arr,int start,int end){
    while(1){
    if(arr[start]==key)
        return 1;
    if(start>end)
        return 0;
    int mid=(start+end)/2;
    if(arr[mid]<key)
        start=mid+1;
    else
        end=mid-1;
    }
}
int insertsortasc(int *arr,int k)
{
    for(int i=1;i<k;i++){
        int value=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
}
int main(){
    printf("Enter the number of element you want to enter: ");
    int n,i,key,result;
    scanf("%d",&n);
    int *arr;
    arr=malloc(sizeof(int)*n);
    printf("Enter the values %d: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",(arr+i));
    insertsortasc(arr,n);
    printf("Enter the value you want to search: \n");
    scanf("%d",&key);
    result=BinarySearch(key,arr,0,n);
    if(result)
        printf("\t\tElement Found!!!!!\n");
    else
        printf("\t\tElement Not Found :(\n");
    return 0;
}