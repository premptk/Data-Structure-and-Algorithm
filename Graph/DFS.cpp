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

int component(vector<int> adj[], int v)
{
    bool visited[v];
    int count=0;
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            count++;
            dfs(adj, i, v, visited);
        }
    }
    cout<<"\n";
    return count;
}

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";
    for(int u : adj[s])
    {
        if(visited[u]==false)
            DFSRec(adj, u, visited);
    }
}


void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    DFSRec(adj, s, visited);
}

void connectedDFS(vector<int> adj[], int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            DFSRec(adj, i, visited);
        }
    }
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
    printGraph(adj, v);
    cout<<component(adj,v)<<endl;
    DFS(adj,v,0);
    cout<<"\n";
    connectedDFS(adj,v);
    return 0;
}
