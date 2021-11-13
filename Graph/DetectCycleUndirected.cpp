#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

bool DFSCheck(vector<int> adj[], int s, int visited[], int parent)
{
    visited[s] = true;
    for(int u : adj[s])
    {
        if(visited[u]==false)
        {
            if(DFSCheck(adj,u,visited,s)==true)
            return true;
        }
        else if(u!=parent)
            return true;
    }
    return false;
}

bool DetcycleUNdirec(vector<int> adj[], int v)
{
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(DFSCheck(adj,i,visited,-1)==true)
                return true;
        }
    }
    return false;
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,0,3);
    addedge(adj,4,5);
    cout<<DetcycleUNdirec(adj,v);
    return 0;
}
