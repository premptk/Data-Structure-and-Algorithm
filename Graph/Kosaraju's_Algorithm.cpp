#include<bits/stdc++.h>
using namespace std;

//               Kosaraju's Algorithm
// 1. Sort all nodes in order of their finishing time. (Topological Sort)
// 2. Transpose the Graph.
// 3. DFS according to the the order of their finishing time.

void dfs(vector<int> adj[], int node, vector<bool> &visited, stack<int> &st)
{
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(!visited[it])
            dfs(adj,it,visited,st);
    }
    st.push(node);
}

void revdfs(vector<int> transpose[], vector<bool> &visited, int node)
{
    cout<<node<<" ";
    visited[node]=true;
    for(auto it : transpose[node])
    {
        if(!visited[it])
        {
            revdfs(transpose,visited,it);
        }
    }
}

int main()
{
    int n=6;
    vector<int> adj[n];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(5);
    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=1;i<n;i++)
    {
        if(!visited[i])
            dfs(adj,i,visited,st);       // Topological Sort
    }

    vector<int> transpose[n];
    for(int i=1;i<n;i++)
    {
        visited[i]=0;
            for(auto it : adj[i])
                transpose[it].push_back(i);
    }

    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!visited[node])
        {
            cout<<"SCC -  ";
            for(auto it : transpose[node])
                revdfs(transpose,visited,it);
            cout<<"\n";
        }
    }
    return 0;
}
