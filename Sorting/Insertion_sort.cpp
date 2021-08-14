#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
     int key,j;
     for(int i=0;i<n;i++)
     {
          j = i-1;
          key = arr[i];
          while(j<n && arr[j] > key)
          {
               arr[j+1] = arr[j];
               j--;
          }
          arr[j+1] = key;
     }
}

int main()
{
     int arr[]={20, 10, 15, 25, 23};
     int n = sizeof(arr)/sizeof(arr[0]);
     insertion_sort(arr, n);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
