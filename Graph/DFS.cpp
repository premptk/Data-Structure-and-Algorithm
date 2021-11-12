#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], int x, int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    queue<int> q;
    visited[x] = true;
    q.push(x);
    while(q.empty()==false)
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int v : adj[u])
        {
            if(visited[v]==false)
            {
                q.push(v);
                visited[v]=true;
            }
        }
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
    dfs(adj,0,v);
    return 0;
}
