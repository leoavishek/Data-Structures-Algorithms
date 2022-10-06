#include <stdio.h>

  void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) 
  {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) 
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void Build_Heap(int arr[], int n)
  {
  	  int i ;
      for ( i = n / 2 - 1 ; i >= 0; i--)
      heapify(arr, n, i);

  }

  void insert(int a[],int *p, int item)
  {   
      int n = *p ;
      n++;
      a[n-1]=item ;
      int i=n-1;
      int parent = i/2 ;
      while(i>0 && a[parent]<item)
      {
          a[i]=a[parent];
          i=parent;
          parent=i/2;
      }
      a[i]=item ;
      printf("Element inserted successfully \n") ;
  }
  
  int delete_max(int a[], int n)
  {   int item ;
      if(n==1) return a[0] ;
      else
         {
             item = a[0] ;
             a[0] = a[n-1] ;
             n-- ;
             heapify(a,n,0);
         }
         return item ;
  }
  
  int main() 
  {
    int n , i , A[50] , item;
    printf("Enter size of array :");
    scanf("%d",&n);
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    
    Build_Heap(A, n);
    
    printf("Enter element to be added : \n");
    scanf("%d",&item);
    insert(A,&n,item);
   
    for ( i = 0; i < n+1 ; i++)
      printf("%d ", A[i]);
      
    int p = delete_max(A,n);
    printf("\nThe deleted item is : %d ", p ) ;
  }
  
