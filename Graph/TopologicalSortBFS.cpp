#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);    //Directed Graph
}

void print(vector<int> adj[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" : ";
        for(int x: adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}

void BFSTopoSort(vector<int> adj[], int n)
{
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
                for(auto it : adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]<=0)
                    {
                        q.push(it);
                    }
                }

        }
}

int main()
{
    int n=5;
    vector<int> adj[n];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,3,1);
    addedge(adj,3,4);
    print(adj,n);
    cout<<"\n";
    BFSTopoSort(adj,n);
    return 0;
}
