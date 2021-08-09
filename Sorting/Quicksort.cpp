#include<bits/stdc++.h>
using namespace std;

int hoarse(int arr[], int l, int h)
{
     int i=l-1,j=h+1;
     // int p = rand(l,h);
     // swap(arr[l],arr[p]);
     int pivot = arr[l];
     while(true)
     {
          do
          {
               i++;
          } while (arr[i] < pivot);
          do
          {
               j--;
          } while (arr[j] > pivot);
          if(i>=j) return j;
          swap(arr[i],arr[j]);
     }
}

void Q_sort(int arr[], int l, int r)
{
     if(l<r)
     {
          int p = hoarse(arr,l,r);
          Q_sort(arr,l,p);
          Q_sort(arr,p+1,r);
     }
}

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
          cin>>arr[i];
     Q_sort(arr,0,n-1);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
