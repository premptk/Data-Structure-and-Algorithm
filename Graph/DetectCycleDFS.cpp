#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void printgraph(vector<int> g[], int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<"\n";
    }
}

void DFSRec(vector<int> adj[], int u, vector<bool>& visited)
{
    visited[u]=true;
    cout<<u<<" ";
    for(int it : adj[u])
    {
        if(visited[it]==false)
            DFSRec(adj,it,visited);
    }
}

void DFS(vector<int> g[], int v)
{
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            DFSRec(g,i,visited);
    }
}

bool cycleDFS(vector<int> adj[], int parent, int node, vector<bool> &visited)
{
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(visited[it]==false){
            if(cycleDFS(adj, node, it, visited))   return true;}
        else if(it!=parent)
            return true;
    }
    return false;
}


bool checkCycle(vector<int> adj[], int v)
{
    vector<bool> visited(v,0);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(cycleDFS(adj,-1,i,visited))
                return true;
        }
    }
    return false;
}



int main()
{
    int v=4;
    vector<int> g[v];
    addedge(g,0,1);
    addedge(g,0,2);
    addedge(g,0,3);
    // addedge(g,1,2);    // add this for cycle
    printgraph(g,v);
    cout<<"\n";
    DFS(g,v);
    cout<<"\n";
    if(checkCycle(g,v)) cout<<"Cycle exist!";
    else cout<<"No Cycle exist!";
    return 0;
}
