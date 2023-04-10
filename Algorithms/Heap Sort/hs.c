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

    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void Build_Heap(int arr[], int n)
  {
      for (int i = n / 2 - 1 ; i >= 0; i--)
      heapify(arr, n, i);

  }
  
  void heapSort(int arr[], int n) 
  {
    Build_Heap(arr,n);
    for (int i = n - 1; i >= 0; i--) 
    {
      swap(&arr[0], &arr[i]);
      n--;
      heapify(arr, i, 0);
    }
  }

  int main() 
  {
    int n , i ;
    printf("Enter size of array :");
    scanf("%d",&n);
    int A[n];
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    
    heapSort(A, n);
  
    printf("Sorted array is \n");
    for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
    printf("\n");
  }
