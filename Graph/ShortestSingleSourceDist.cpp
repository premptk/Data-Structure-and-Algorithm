#include<bits/stdc++.h>
using namespace std;

void addedge(vector<pair<int,int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
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

void shortestPath(vector<pair<int,int>> adj[], int n, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(dist[it.first] > it.second + dist[node]){
                dist[it.first] = it.second + dist[node];
                q.push(it.first);
            }
        }
    }

    for(auto it: dist)
        cout<<it<<" ";
}

int main()
{
    int n=5;
    vector<pair<int,int>> adj[n];
    addedge(adj,0,1,1);
    addedge(adj,0,2,1);
    addedge(adj,1,2,2);          // Cycle
    addedge(adj,3,1,2);
    addedge(adj,3,4,1);
    addedge(adj,0,4,3);
    print(adj,n);
    shortestPath(adj,n,0);
    return 0;
}
