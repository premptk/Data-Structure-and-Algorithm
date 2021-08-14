#include<bits/stdc++.h>
using namespace std;

void bucketsort(int arr[], int n, int k)
{
     int max_ele = arr[0];
     for(int i=1;i<n;i++)
          max_ele = max(max_ele,arr[i]);
     max_ele++;
     vector<int> bkt[k];
     for(int i=0;i<n;i++)
          bkt[(k*arr[i])/max_ele].push_back(arr[i]);
     for(int i=0;i<k;i++)
          sort(bkt[i].begin(), bkt[i].end());
     int index=0;
     for(int i=0;i<k;i++)
     {
          for(int j=0;j<bkt[i].size();j++)
               arr[index++] = bkt[i][j];
     }

}

int main()
{
     int arr[]={30, 40, 10, 80, 5, 12, 70};
     int n = sizeof(arr)/sizeof(arr[0]);
     int k;
     cout<<"Enter number of partition: ";
     cin>>k;
     bucketsort(arr, n, k);
     for(int i=0;i<n;i++)
          cout<<arr[i]<<" ";
     return 0;
}
