#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
     int max_sum=arr[0],cur_sum=arr[0];
     for(int i=1;i<n;i++)
     {
          if(arr[i] < (cur_sum + arr[i]))
               cur_sum = cur_sum + arr[i];
          else
               cur_sum = arr[i];
          if(max_sum < cur_sum)
               max_sum = cur_sum;
     }
     return max_sum;
}

int main()
{
     int arr[] = {-1, -2, 1, 3,-1, 5};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout<<kadane(arr,n)<<endl;
     return 0;
}
