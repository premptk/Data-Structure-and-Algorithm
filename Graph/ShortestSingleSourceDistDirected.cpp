#include<bits/stdc++.h>
using namespace std;

void addedge(vector<pair<int,int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
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

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int,int>> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                findTopoSort(it.first, vis, st, adj); 
            }
        }
        st.push(node); 
    }

void shortestPath(vector<pair<int,int>> adj[], int n, int src)
{
    //Toplogical Sorting
    stack<int> st; 
    vector<int> vis(n, 0); 
        for(int i = 0;i<n;i++) {
            if(vis[i] == 0) {
                findTopoSort(i, vis, st, adj); 
            }
        }

    vector<int> dist(n, INT_MAX);
    dist[src]=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX){
            for(auto it : adj[node])
            {
                if(dist[it.first] > it.second + dist[node]){
                    dist[it.first] = it.second + dist[node];
                }
            }
        }
    }
    for(auto it: dist)
        if(it==INT_MAX)cout<<"INF "; else cout<<it<<" ";
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
