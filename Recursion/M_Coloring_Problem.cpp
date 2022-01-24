bool isSafe(int node, int color[],int c, int N, bool graph[101][101])
{
    for(int i=0;i<N;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==c)
            return false;
    }
    return true;
}


bool solve(int ind, int color[], int m, int N, bool graph[101][101])
{
    if(ind == N)
    {
        return true;
    }
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(ind,color, i, N, graph))
        {
            color[ind]=i;
            if(solve(ind+1,color,m,N,graph))
                return true;
            color[ind]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    
    int color[N]={0};
    if(solve(0,color,m,N,graph))
        return true;
    else return false;
}
