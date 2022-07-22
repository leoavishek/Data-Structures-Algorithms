/* Merge Sort
This is a sorting algorithm which uses comparision following the divide and conquer technique
Worst Time Complexity    :O(nlogn)
Average Time Complexity  :O(nlogn)
Best Time Complexity     :O(nlogn)
*/
#include<stdio.h>
#include<stdlib.h>
//Driver Code
void Merge(int *arr,int p, int q, int r){
    int n1=q-p;
    int n2=r-q;
    int i,j;
    int *left=malloc(sizeof(int)*n1);
    int *right=malloc(sizeof(int)*n2);
    for(i=0;i<n1;i++){
        left[i]=arr[p+i];
    }
    for(j=0;j<n2;j++){
        right[j]=arr[q+j];
    }
    left[n1] =100000;
    right[n2]=100000;
    i=0;
    j=0;
    for(int k=p;k<r;k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
    }
}
void MergeSort(int *arr,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}
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
    MergeSort(arr,0,n);
    printf("\tAfter Swapping \n");
    for(int i=0;i<n;i++)
    printf("%d) %d\n",i+1,arr[i]);
    return 0;
}