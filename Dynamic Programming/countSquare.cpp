#include<bits/stdc++.h>
using namespace std;

int countSquare(vector<vector<int>> &matrix)
{
    int n = matrix.size();         // rows
    int m = matrix[0].size();      // column
    vector<vector<int>> dp (n, vector<int> (m, 0));

    for(int i=0;i<n;i++)
        dp[i][0] = matrix[i][0];
    
    for(int j=0;j<m;j++)
        dp[0][j] = matrix[0][j];

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j], 
                            min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> matrix = {{1,1,0},{1,1,1},{1,1,1}};
    cout<<countSquare(matrix);
    return 0;
}
