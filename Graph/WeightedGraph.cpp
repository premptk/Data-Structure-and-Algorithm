#include<bits/stdc++.h>
using namespace std;

void addedge(vector<pair<int,int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    // adj[v].push_back(u);
}

void print(vector<pair<int,int>> adj[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" : ";
        for(auto it: adj[i])
            cout<<"("<<it.first<<"  wt="<<it.second<<")  ";
        cout<<"\n";
    }
}


int main()
{
    int n=5;
    vector<pair<int,int>> adj[n];
    addedge(adj,0,1,1);
    addedge(adj,0,2,1);
    // addedge(adj,1,2);          //Cycle
    addedge(adj,3,1,2);
    addedge(adj,3,4,1);
    addedge(adj,0,4,3);
    print(adj,n);
    
    // Output:
    // 0 : (1  wt=1)  (2  wt=1)  (4  wt=3)  
    // 1 :
    // 2 :
    // 3 : (1  wt=2)  (4  wt=1)
    // 4 :

    return 0;
}
