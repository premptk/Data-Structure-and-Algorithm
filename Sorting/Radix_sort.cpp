#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[], int n, int exp)
{
     int count[10]={0};
     for(int i=0;i<n;i++)
          count[(arr[i]/exp)%10]++;

     for(int i=1;i<10;i++)
          count[i] = count[i-1] + count[i];

     int output[n] = {0};
     for(int i=n-1;i>=0;i--)
     {
          output[count[(arr[i]/exp)%10]-1] = arr[i];
          count[(arr[i]/exp)%10]--;
     }
     for(int i=0;i<n;i++)
          arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
     int max = arr[0];
     for(int i=1;i<n;i++)
          if(arr[i] > max)
               max=arr[i];
     
     for(int i=1;max/i>0;i=i*10)
          countsort(arr, n, i);
}


int main()
{
     int arr[]={12, 5, 3, 15, 20, 1};
     int n = sizeof(arr)/sizeof(arr[0]);
     radixsort(arr,n);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
