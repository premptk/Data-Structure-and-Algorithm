#include<bits/stdc++.h>
using namespace std;

void ini_lps(int lps[], string txt, string pat)
{
    int len=0;
    lps[0]=0;   //first will always be 0
    int i=1;
    while(i < pat.length())
    {
        if(lps[i]==lps[len])  //same character
        {
            len++;
            lps[i]=len;
            i++;
        }
        else //not same character
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                //len==0
                lps[i]=0;
                i++;    
            }
        } 
    }
}

void kmp(string txt, string pat)
{
    int lps[pat.length()];
    ini_lps(lps, txt, pat);
    int i=0,j=0;
    while(i < pat.length())
    {
        if(pat[i] == txt[j])
        {
            i++;
            j++;
        }
        if(i == pat.length())
        {
            cout<<"Pattern found at "<<(j - i)<<endl;
            i = lps[i-1];
        }
        else if(j < txt.length() && pat[i]!=txt[j])
        {
            if(i!=0)
                i = lps[i-1];
            else 
                j++;
        }
    }
    cout<<"Not Found!"<<endl;
}

int main()
{
    string txt, pat;
    cin>>txt>>pat;
    kmp(txt, pat);
    return 0;
}
