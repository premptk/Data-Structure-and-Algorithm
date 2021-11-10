#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<" - ";
        for(int j : adj[i])
            cout<<j<<" ";
        cout<<"\n";
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,0,3);
    printGraph(adj, v);
    return 0;
}
