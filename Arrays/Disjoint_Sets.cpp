#include<iostream>
using namespace std;

int findPar(int arr[], int parent[], int u)
{
    if(parent[u]==u)
        return u;
    return parent[u] = findPar(arr, parent, parent[u]);
}

void getUnion(int arr[], int parent[],int rank[], int n, int x, int y)
{
    int u = findPar(arr,parent,x);
    int v = findPar(arr,parent,y);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int parent[n],rank[n];
    for(int i=0;i<n;i++)
        parent[i]=i,rank[i]=0;
    getUnion(arr,parent,rank,n,2,3);
    cout<<findPar(arr,parent,2)<<endl;
    cout<<findPar(arr,parent,3);
    return 0;
}
