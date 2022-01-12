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

void dijkstra(vector<pair<int,int>> adj[], int n,int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> distTo(n,INT_MAX);
    distTo[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto it : adj[prev])
        {
            int next=it.first;
            int nextDist = it.second;
            if(distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next],next});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<distTo[i]<<" ";
    }
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
    dijkstra(adj,n,0);
    return 0;
}
