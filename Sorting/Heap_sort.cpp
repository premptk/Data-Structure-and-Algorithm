#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
     int largest=i,left=2*i+1, right=2*i+2;
     if(left<n && arr[left]>arr[largest]) largest=left;
     if(right<n && arr[right]>arr[largest]) largest=right;
     if(largest!=i)
     {
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
     }
}

void buildheap(int arr[], int n)
{
     for(int i=(n-2)/2;i>=0;i--)
          heapify(arr,n,i);
}


void heapSort(int arr[], int n)
{
     buildheap(arr,n);
     for(int i=n-1;i>=1;i--)
     {
          swap(arr[0], arr[i]);
          heapify(arr,i,0);
     }
}

int main()
{
     int arr[]={12,11,13,5,6};
     int n = sizeof(arr)/sizeof(arr[0]);
     heapSort(arr,n);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
