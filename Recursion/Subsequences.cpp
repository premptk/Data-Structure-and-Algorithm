#include<iostream>
#include<vector>
using namespace std;

void subset(string str, int i,string ds)
{
    if(i == str.length())
    {
        cout<<ds<<" ";
        return;
    }
    subset(str,i+1,ds+str[i]);
    subset(str,i+1,ds);
}

void sumK(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        if(s == sum)
        {
            for(auto it : ds)
                cout<<it<<" ";
                cout<<"\n";
        }
        return;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    sumK(ind+1,ds,s,sum,arr,n);

    s-=arr[ind];
    ds.pop_back();
    sumK(ind+1,ds,s,sum,arr,n);
}

bool OnlyOnesumK(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        if(s == sum)
        {
            for(auto it : ds)
                cout<<it<<" ";
                cout<<"\n";
            return true;
        }
        return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(OnlyOnesumK(ind+1,ds,s,sum,arr,n)==true) return true;

    s-=arr[ind];
    ds.pop_back();
    if(OnlyOnesumK(ind+1,ds,s,sum,arr,n)==true) return true;
    return false;
}

int CountSubs(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(ind==n)
    {
        if(sum==s)
            return 1;
        else return 0;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];
    int l = CountSubs(ind+1,ds,s,sum,arr,n);
    
    ds.pop_back();
    s-=arr[ind];
    int r = CountSubs(ind+1,ds,s,sum,arr,n);
    return l+r;
}

int main()
{
    // to print all subsequences of a string
    string str="ABC";
    subset(str,0,"");

    cout<<"\n";


    // to print if sum is equal to the sum of subsequences
    int arr[] = {1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    sumK(0,ds,0,sum,arr,n);

    // to print only one subsequence if sum is equal to given number
    // return true/false
    // avoid recursion for false
    int arr2[] = {1,2,1};
    int n2=3;
    int sum2=2;
    vector<int> ans;
    OnlyOnesumK(0,ans,0,sum2,arr2,n2);

    // to print count of subsequences present 
    // return 1/0
    // return l+r
    int arr3[] = {1,2,1};
    int n3=3;
    int sum3=2;
    vector<int> ans2;
    cout<<CountSubs(0,ans,0,sum2,arr2,n2);

    return 0;
}
