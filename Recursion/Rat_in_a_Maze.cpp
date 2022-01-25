#include<bits/stdc++.h>
using namespace std;

void solve(int i, int j, int m, int n, vector<vector<int>> &arr, string move, vector<vector<int>> &visited, int di[], int dj[], vector<string> &ans)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for(int ind=0;ind<4;ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti>=0 && nextj >=0 && nexti < n && nexti < n && arr[nexti][nextj]==1 && !visited[nexti][nextj])
        {
            visited[i][j]=1;
            solve(nexti,nextj,m,n,arr,move + dir[ind],visited,di,dj,ans);
            visited[i][j]=0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n=4,m=4;
    vector<vector<int>> visited(n, vector<int> (n,0));
    int di[] = {+1,0,0,-1};
    int dj[] = {0,-1,1,0};
    vector<string> ans;
    if(arr[0][0]==1)
        solve(0,0,m,n,arr,"",visited,di,dj,ans);
    
    for(auto it : ans)
        cout<<it<<" ";
    return 0;
}
