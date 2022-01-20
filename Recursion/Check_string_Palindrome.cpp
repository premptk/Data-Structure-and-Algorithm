#include<bits/stdc++.h>
using namespace std;

bool checkPalin(string str,int i, int n)
{
    if(i >= n/2)
        return true;
    if(str[i] != str[n-1-i])
        return false;
    return checkPalin(str,i+1, n);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string str;
    cin>>str;
    cout<<checkPalin(str,0,str.length());

    return 0;
}
