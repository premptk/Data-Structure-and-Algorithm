#include<bits/stdc++.h>
using namespace std;

int mergeArr(int arr[], int temp[], int left, int mid,int right)
{
    int count=0;
    int i=left,j=mid,k=left;
    while(i<=mid-1 && j<=right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            count += (mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    
    for(i=left;i<=right;i++)
        arr[i]=temp[i];

    return count;
}

int mergeSort(int arr[],int temp[], int l, int r)
{
    int count=0,mid;
    if(r>l){
        mid = (r+l)/2;
        count += mergeSort(arr,temp, l,mid);
        count += mergeSort(arr,temp, mid+1,r);
        count += mergeArr(arr,temp, l, mid+1,r);
    }
    return count;
}

int main()
{
    int n;
    int arr[] = {1,20,6,4,5};
    n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int temp[n];
    cout<<mergeSort(arr,temp,0,n-1);
    return 0;
}
