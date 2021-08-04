#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
     int n1 = m-l+1;
     int n2 = h-m;
     int A[n1],B[n2];
     for(int i=0;i<n1;i++)
          A[i] = arr[l+i];
     for(int i=0;i<n2;i++)
          B[i] = arr[m+1+i];
     
     int i=0,j=0,k=l;
     while(i<n1 && j<n2)
     {
          if(A[i] <= B[j])
               arr[k++] = A[i++];
          else
               arr[k++] = B[j++];
     }
     while(i<n1){arr[k++] = A[i++]; }
     while(j<n2){arr[k++] = B[j++];}
}

void mergesort(int arr[],int l, int r)
{
     if(r > l)
     {
          int m = l+(r-l)/2;
          mergesort(arr,l,m);
          mergesort(arr,m+1,r);
          merge(arr,l,m,r);
     }
}

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
          cin>>arr[i];
     mergesort(arr,0,n-1);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
