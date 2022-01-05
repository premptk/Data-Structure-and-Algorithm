#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }

vector<int> topoSort(int N, vector<int> adj[]) {
        stack<int> st; 
        vector<int> vis(N, 0); 
        for(int i = 0;i<N;i++) {
            if(vis[i] == 0) {
                findTopoSort(i, vis, st, adj); 
            }
        }
        vector<int> topo;
        while(!st.empty()) {
            topo.push_back(st.top()); 
            st.pop(); 
        }
        return topo; 
        
}


int main()
{
    int n=5;
    vector<int> adj[n];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,3,1);
    addedge(adj,3,4);
    vector<int> ans;
    ans = topoSort(n, adj);
    for(auto it : ans)
        cout<<it<<" ";
    return 0;
}
