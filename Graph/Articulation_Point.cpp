#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> artiPoint(vector<int> adj[], int node, int parent, int &buffer, vector<bool> &visited, vector<int> &low, vector<int> &intime,vector<int> &arti)
{
    visited[node]=true;
    low[node] = intime[node] = buffer++;
    int child=0;
    for(auto it : adj[node])
    {
        if(it == parent)
            continue;
        if(!visited[it])
        {
            artiPoint(adj,it,node,buffer,visited,low,intime,arti);
            low[node] = min(low[node], low[it]);
            if(low[it] >= intime[node] && parent!=-1)
                arti[node]=1;
            child++;
        }
        else
        {
            low[node] = min(low[node], intime[it]);
        }

    if(parent==-1 && child>1)
        arti[node]=1;
    }
    return arti;
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
    vector<int> arti(n,0);
    int buffer=1;
    for(int i=1;i<n;i++)
    {
        if(!visited[i])
            arti = artiPoint(adj,i,-1,buffer,visited,low,intime,arti);
    }
    for(int i=1;i<n;i++)
        if(arti[i])  cout<<i<<" ";
    return 0;
}
