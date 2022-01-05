#include<bits/stdc++.h>
using namespace std;

int maxReach(int arr[], int n)
{
    if(n==0)
        return 0;

    if(arr[0]==0)
        return -1;

    int maxR = arr[0];
    int jump=1;
    int steps=arr[0];

    for(int i=1;i<n;i++)
    {
        if(i==n-1)
            return jump;
        maxR = max(maxR, i+arr[i]);
        steps--;
        while(steps==0)
        {
            jump++;
            if(i >= maxR)
                return -1;
            steps = maxR-i;
        }
    }
    return jump;    
}

int main()
{
    int arr[] = {1,1,2,5,2,1,0,0,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<maxReach(arr,size);
    return 0;
}
