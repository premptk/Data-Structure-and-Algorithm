#include<bits/stdc++.h>
using namespace std;

void powerset(string str, int i, string curr)
{
    // Time Complexity => O(2^n)
    if(i==str.length())
    {
        cout<<curr<<endl;
        return;
    }
    powerset(str,i+1,curr+str[i]);
    powerset(str,i+1,curr);
}

int main()
{
    string str = "PremRanjan";
    powerset(str,0,"");
    return 0;
}
