#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int node, int parent, int &buffer, vector<bool> &visited, vector<int> &low, vector<int> & intime)
{
    visited[node]=true;
    low[node] = intime[node] = buffer++;
    for(auto it : adj[node])
    {
        if(it == parent)
            continue;
        if(!visited[it])
        {
            dfs(adj, it, node, buffer, visited, low, intime);
            low[node] = min(low[node], low[it]);
            if(low[it] > intime[node])
                cout<<node<<" "<<it<<"\n";
        }
        else
        {
            low[node] = min(low[node], intime[it]);
        }
    }
}

int main()
{
    int n=11;
    vector<int> adj[n];
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,4,3);
    addedge(adj,4,5);
    addedge(adj,5,6);
    addedge(adj,6,9);
    addedge(adj,6,7);
    addedge(adj,7,8);
    addedge(adj,8,10);
    addedge(adj,9,8);
    vector<int> low(n,-1);
    vector<int> intime(n,-1);
    vector<bool> visited(n,false);
    int buffer=1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(adj,i,-1,buffer,visited,low,intime);
    }
    return 0;
}
