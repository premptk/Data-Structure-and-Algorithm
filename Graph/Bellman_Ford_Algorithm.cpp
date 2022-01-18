#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,wt;
    node(){}
    node(int x, int y, int w)
    {
        u=x;
        v=y;
        wt=w;
    }
};

int main()
{
    int n=6;
    vector<node> adj;
    adj.push_back(node(0,1,5));
    adj.push_back(node(1,5,-3));
    adj.push_back(node(1,2,-2));
    adj.push_back(node(5,3,1));
    adj.push_back(node(3,2,6));
    adj.push_back(node(3,4,-2));
    adj.push_back(node(2,4,3));

    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(auto it : adj)
        {
            if(dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    
    for(int i=0;i<1;i++)
    {
        for(auto it : adj)
        {
            if(dist[it.u] + it.wt < dist[it.v])
            {
                cout<<"Negative cycle detected!\n";
            }
        }
    }

    for(auto it : dist)
        cout<<it<<" ";
    return 0;
}
