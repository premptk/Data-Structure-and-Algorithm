#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n)
{
    int len=1;
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(temp[i] < arr[i])
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = 
                lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}

int main()
{
    int n=7;
    vector<int> arr = {10,9,2,5,3,7,101,50};
    cout<<LIS(arr,n)<<endl;
    return 0;
}
