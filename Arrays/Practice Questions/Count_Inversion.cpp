#include<bits/stdc++.h>
using namespace std;

int merge(int left, int mid, int right, vector<int> &arr)
{
    int lt = mid-left+1;
    int rt = right-mid;
    vector<int> res(lt+rt);
    vector<int> leftarr(lt), rightarr(rt);

    for(int i=0;i<lt;i++)
        leftarr[i] = arr[left + i];

    for(int i=0;i<rt;i++)
        rightarr[i] = arr[mid + i+1];

    int inv_count = 0;
    int k=0;
    int i=0,j=0;
    while(i<lt && j<rt)
    {
        if(leftarr[i] <= rightarr[j]){
            res[k++] = leftarr[i++];
        }
        else{
            res[k++] = rightarr[j++];
            inv_count += (mid-i);
        }
    }

    while(i<lt){ res[k++] = leftarr[i++]; }
    while(j<rt){ res[k++] = rightarr[j++]; }

    for(int i=0;i<(lt+rt);i++)
        arr[left + i] = res[i];
    
    return inv_count;
}

int mergesort(int left, int right, vector<int> &arr)
{
    int inv_count = 0;
    if(left<right)
    {
        int mid = (left+right)>>1;
        inv_count += mergesort(left,mid,arr);
        inv_count += mergesort(mid+1, right,arr);
        inv_count += merge(left,mid,right,arr);
    }
    return inv_count;
}

int main()
{
    // count inversion of array
    vector<int> arr = {8,4,2,1};
    int n = arr.size();
    int inv_count = 0;
    inv_count = mergesort(0,n-1,arr);
    cout<<inv_count<<endl;
    return 0;
}
