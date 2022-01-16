#include<bits/stdc++.h>
using namespace std;
struct node
{
    int wt,u,v;
    node(){}
    node(int weight, int x, int y)
    {
        wt = weight;
        u = x;
        v = y;
    }
};

int findPar(int u, vector<int> &parent)
{
    if(u==parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(node a, node b)
{
    return a.wt < b.wt;   //ascending order
}

int main()
{
    int n,N;
    cin>>n>>N;
    vector<node> edges;
    for(int i=0;i<N;i++)
    {
        int u,v,wt;
        cin>>wt>>u>>v;
        edges.push_back(node(wt,u,v));
    }
    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;
    vector<int> rank(n,0);

    int cost=0;
    vector<pair<int,int>> Mst;
    for(auto it : edges)
    {
        if(findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            Mst.push_back({it.u,it.v});
            unionn(parent, rank, it.u, it.v);
        }
    }

    for(auto it : Mst)
        cout<<it.first<<" "<<it.second<<"\n";
    cout<<"Total cost = "<<cost;
    return 0;
}
